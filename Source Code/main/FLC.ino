float error_1, error, dError, pwm, sp = 1.65;
float UErrorN, UdErrorN, Ututup;
float UErrorZ, UdErrorZ, Usedang;
float UErrorP, UdErrorP, Ubuka;
float rule1, rule2a, rule2b, rule3a, rule3b, rule4, rule5a, rule5b, rule6a, rule6b, rule7;

void error_pH_N()
{
    if(error <= -1){UErrorN = 1;}
    else if(error >= -1 && error <= 0){UErrorN = (0 - error)/1;}
    else if(error >= 0){UErrorN = 0;}
}

void error_pH_Z()
{
    if(error <= -1){UErrorZ = 0;}
    else if(error <= 0 && error >= -1){UErrorZ = (error + 1)/1;}
    else if(error >= 0 && error <= 1){UErrorZ = (1 - error)/1;}
    else if(error >= 1){UErrorZ = 0;}
}

void error_pH_P()
{
    if(error <= 0){UErrorP = 0;}
    else if(error >= 0 && error <= 1){UErrorP = (error - 0)/1;}
    else if(error >= 1){UErrorP = 1;}
}

void dError_pH_N()
{
    if(dError <= -1){UdErrorN = 1;}
    else if(dError >= -1 && dError <= 0){UdErrorN = (0 - dError)/1;}
    else if(dError >= 0){UdErrorN = 0;}
}

void dError_pH_Z()
{
    if(dError <= -1){UdErrorZ = 0;}
    else if(dError <= 0 && dError >= -1){UdErrorZ = (dError + 1)/1;}
    else if(dError >= 0 && dError <= 1){UdErrorZ = (1 - dError)/1;}
    else if(dError >= 1){UdErrorZ = 0;}
}

void dError_pH_P()
{
    if(dError <= 0){UdErrorP = 0;}
    else if(dError >= 0 && dError <= 1){UdErrorP = (dError - 0)/1;}
    else if(dError >= 1){UdErrorP = 1;}
}

void fuzifikasi()
{
    error_pH_N();
    error_pH_Z();
    error_pH_P();
    dError_pH_N();
    dError_pH_Z();
    dError_pH_P();
}

void rule()
{
    fuzifikasi();
    //if error = N and dError = N Then Buka
    float x1 = min(UErrorN, UdErrorN);
    rule1 = 45 + (30 * x1); // Buka
    //if error = N and dError = Z Then Sedang
    float x2 = min(UErrorN, UdErrorZ);
    rule2a = 45 * x2; // Sedang Up
    rule2b = 75 - (30 * x2); //Sedang Down
    //if error = Z and dError = N Then Sedang
    float x3 = min(UErrorZ, UdErrorN);
    rule3a = 45 * x3; // Sedang Up
    rule3b = 75 - (30 * x3); //Sedang Down
    //if error = Z and dError = Z Then Tutup
    float x4 = min(UErrorZ, UdErrorZ);
    rule4 = 0 * x4; // Tutup
    // if error = Z and dError = P Then Sedang
    float x5 = min(UErrorZ, UdErrorP);
    rule5a = 45 * x5; // Sedang Up
    rule5b = 75 - (30 * x5); //Sedang Down
    // if error = P and dError = Z Then Sedang
    float x6 = min(UErrorP, UdErrorZ);
    rule6a = 45 * x6; // Sedang Up
    rule6b = 75 - (30 * x6); //Sedang Down
    //if error = P and dError = P Buka
    float x7 = min(UErrorP, UdErrorP);
    rule7 = 45 + (30 * x7); // Buka
    def = ((rule1 * x1)+(rule2a * x2)+(rule2b * x2)+(rule3a * x3)+(rule3b * x3)+(rule4 * x4)+(rule5a * x5)+(rule5b * x5)+(rule6a * x6)+(rule6b * x6)+(rule7 * x7))/(x1+x2+x2+x3+x3+x4+x5+x5+x6+x6+x7);
}

void defuzzyfikasi()
{
    error_1 = error;
    error = sp - pHValue;
    dError = error - error_1;
    rule();
    kran1.write(round(def));
}