EESchema Schematic File Version 4
LIBS:ESP32-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Conn_01x04_Male J1
U 1 1 5F815AB8
P 2800 1550
F 0 "J1" H 2908 1831 50  0000 C CNN
F 1 "A MIX" H 2908 1740 50  0000 C CNN
F 2 "DIY CONN:JST_XH_B4B-XH-A_1x04_P2.50_DIY" H 2800 1550 50  0001 C CNN
F 3 "~" H 2800 1550 50  0001 C CNN
	1    2800 1550
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J2
U 1 1 5F81613D
P 2800 2100
F 0 "J2" H 2908 2381 50  0000 C CNN
F 1 "B MIX" H 2908 2290 50  0000 C CNN
F 2 "DIY CONN:JST_XH_B4B-XH-A_1x04_P2.50_DIY" H 2800 2100 50  0001 C CNN
F 3 "~" H 2800 2100 50  0001 C CNN
	1    2800 2100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J3
U 1 1 5F816668
P 2800 2650
F 0 "J3" H 2908 2931 50  0000 C CNN
F 1 "pH" H 2908 2840 50  0000 C CNN
F 2 "DIY CONN:JST_XH_B4B-XH-A_1x04_P2.50_DIY" H 2800 2650 50  0001 C CNN
F 3 "~" H 2800 2650 50  0001 C CNN
	1    2800 2650
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0114
U 1 1 5F85D590
P 3450 1300
F 0 "#PWR0114" H 3450 1150 50  0001 C CNN
F 1 "+5V" H 3465 1473 50  0000 C CNN
F 2 "" H 3450 1300 50  0001 C CNN
F 3 "" H 3450 1300 50  0001 C CNN
	1    3450 1300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0115
U 1 1 5F85D9FB
P 3400 2950
F 0 "#PWR0115" H 3400 2700 50  0001 C CNN
F 1 "GND" H 3405 2777 50  0000 C CNN
F 2 "" H 3400 2950 50  0001 C CNN
F 3 "" H 3400 2950 50  0001 C CNN
	1    3400 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 1750 3400 2300
Connection ~ 3450 2000
Wire Wire Line
	3450 2000 3450 1450
Wire Wire Line
	3450 2550 3450 2000
Connection ~ 3400 2300
Wire Wire Line
	3400 2300 3400 2850
$Comp
L Connector:Conn_01x03_Male J18
U 1 1 5F8A40D0
P 650 2900
F 0 "J18" H 758 3181 50  0000 C CNN
F 1 "Temp_SNS" H 758 3090 50  0000 C CNN
F 2 "DIY CONN:JST_XH_B3B-XH-A_1X03_P2.50mm_DIY" H 650 2900 50  0001 C CNN
F 3 "~" H 650 2900 50  0001 C CNN
	1    650  2900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0121
U 1 1 5F8B44E6
P 1000 3400
F 0 "#PWR0121" H 1000 3150 50  0001 C CNN
F 1 "GND" H 1005 3227 50  0000 C CNN
F 2 "" H 1000 3400 50  0001 C CNN
F 3 "" H 1000 3400 50  0001 C CNN
	1    1000 3400
	1    0    0    -1  
$EndComp
Text Label 1050 2750 0    50   ~ 0
TEMP_SNS
$Comp
L DCtoDC_LM2596:LM2596 U2
U 1 1 5F871DBD
P 4800 4100
F 0 "U2" H 4800 4415 50  0000 C CNN
F 1 "LM2596" H 4800 4324 50  0000 C CNN
F 2 "DCtoDC:LM2596" H 4800 4375 50  0001 C CNN
F 3 "" H 4800 4375 50  0001 C CNN
	1    4800 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	850  2800 850  2750
$Comp
L Connector:Barrel_Jack_Switch J4
U 1 1 5F89E783
P 3250 4100
F 0 "J4" H 3307 4417 50  0000 C CNN
F 1 "Power Supply" H 3307 4326 50  0000 C CNN
F 2 "Connector_BarrelJack:BarrelJack_Wuerth_6941xx301002" H 3300 4060 50  0001 C CNN
F 3 "~" H 3300 4060 50  0001 C CNN
	1    3250 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:CP_Small C3
U 1 1 5F8B20C5
P 4000 4100
F 0 "C3" H 4088 4146 50  0000 L CNN
F 1 "1000u" H 4088 4055 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D10.0mm_P5.00mm" H 4000 4100 50  0001 C CNN
F 3 "~" H 4000 4100 50  0001 C CNN
	1    4000 4100
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0122
U 1 1 5F8B3CFD
P 5250 3950
F 0 "#PWR0122" H 5250 3800 50  0001 C CNN
F 1 "+5V" H 5265 4123 50  0000 C CNN
F 2 "" H 5250 3950 50  0001 C CNN
F 3 "" H 5250 3950 50  0001 C CNN
	1    5250 3950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0123
U 1 1 5F8B45C7
P 5250 4400
F 0 "#PWR0123" H 5250 4150 50  0001 C CNN
F 1 "GND" H 5255 4227 50  0000 C CNN
F 2 "" H 5250 4400 50  0001 C CNN
F 3 "" H 5250 4400 50  0001 C CNN
	1    5250 4400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0125
U 1 1 5F8BD560
P 4000 4400
F 0 "#PWR0125" H 4000 4150 50  0001 C CNN
F 1 "GND" H 4005 4227 50  0000 C CNN
F 2 "" H 4000 4400 50  0001 C CNN
F 3 "" H 4000 4400 50  0001 C CNN
	1    4000 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 3950 4000 4000
$Comp
L Connector:Conn_01x03_Male J10
U 1 1 5F8FC5E9
P 1950 1550
F 0 "J10" H 2058 1831 50  0000 C CNN
F 1 "OUT1" H 2058 1740 50  0000 C CNN
F 2 "DIY CONN:JST_XH_B3B-XH-A_1X03_P2.50mm_DIY" H 1950 1550 50  0001 C CNN
F 3 "~" H 1950 1550 50  0001 C CNN
	1    1950 1550
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male J11
U 1 1 5F8FD0E6
P 1950 2000
F 0 "J11" H 2058 2281 50  0000 C CNN
F 1 "OUT2" H 2058 2190 50  0000 C CNN
F 2 "DIY CONN:JST_XH_B3B-XH-A_1X03_P2.50mm_DIY" H 1950 2000 50  0001 C CNN
F 3 "~" H 1950 2000 50  0001 C CNN
	1    1950 2000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0133
U 1 1 5F9195E2
P 2450 1300
F 0 "#PWR0133" H 2450 1150 50  0001 C CNN
F 1 "+5V" H 2465 1473 50  0000 C CNN
F 2 "" H 2450 1300 50  0001 C CNN
F 3 "" H 2450 1300 50  0001 C CNN
	1    2450 1300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0134
U 1 1 5F93A53A
P 2400 2650
F 0 "#PWR0134" H 2400 2400 50  0001 C CNN
F 1 "GND" H 2405 2477 50  0000 C CNN
F 2 "" H 2400 2650 50  0001 C CNN
F 3 "" H 2400 2650 50  0001 C CNN
	1    2400 2650
	1    0    0    -1  
$EndComp
Text Label 2350 2350 2    50   ~ 0
OUT3
Text Label 2350 1900 2    50   ~ 0
OUT2
Text Label 2350 1450 2    50   ~ 0
OUT1
Wire Wire Line
	850  2750 1500 2750
$Comp
L power:+3V3 #PWR0135
U 1 1 5F900234
P 4550 1300
F 0 "#PWR0135" H 4550 1150 50  0001 C CNN
F 1 "+3V3" H 4565 1473 50  0000 C CNN
F 2 "" H 4550 1300 50  0001 C CNN
F 3 "" H 4550 1300 50  0001 C CNN
	1    4550 1300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0137
U 1 1 5F95DDE8
P 4000 2000
F 0 "#PWR0137" H 4000 1750 50  0001 C CNN
F 1 "GND" H 4005 1827 50  0000 C CNN
F 2 "" H 4000 2000 50  0001 C CNN
F 3 "" H 4000 2000 50  0001 C CNN
	1    4000 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 2000 4000 1950
$Comp
L Connector:Conn_01x04_Male J6
U 1 1 5F96917B
P 4700 1550
F 0 "J6" H 4808 1831 50  0000 C CNN
F 1 "I2C_1" H 4808 1740 50  0000 C CNN
F 2 "DIY CONN:JST_XH_B4B-XH-A_1x04_P2.50_DIY" H 4700 1550 50  0001 C CNN
F 3 "~" H 4700 1550 50  0001 C CNN
	1    4700 1550
	1    0    0    -1  
$EndComp
Text Label 5150 1650 2    50   ~ 0
SDA
Text Label 5150 1750 2    50   ~ 0
SCL
$Comp
L power:+5V #PWR0138
U 1 1 5F99A43D
P 5300 1300
F 0 "#PWR0138" H 5300 1150 50  0001 C CNN
F 1 "+5V" H 5315 1473 50  0000 C CNN
F 2 "" H 5300 1300 50  0001 C CNN
F 3 "" H 5300 1300 50  0001 C CNN
	1    5300 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 1550 5300 1550
Wire Wire Line
	4900 1450 5250 1450
$Comp
L power:GND #PWR0139
U 1 1 5F9D05CD
P 5250 2000
F 0 "#PWR0139" H 5250 1750 50  0001 C CNN
F 1 "GND" H 5255 1827 50  0000 C CNN
F 2 "" H 5250 2000 50  0001 C CNN
F 3 "" H 5250 2000 50  0001 C CNN
	1    5250 2000
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x06_Female J9
U 1 1 5F8D4930
P 3750 1650
F 0 "J9" H 3642 2035 50  0000 C CNN
F 1 "SD_CARD_Module" H 3642 1944 50  0000 C CNN
F 2 "DIY:SD_Card" H 3750 1650 50  0001 C CNN
F 3 "~" H 3750 1650 50  0001 C CNN
	1    3750 1650
	-1   0    0    -1  
$EndComp
Text Label 4350 1450 2    50   ~ 0
DAT3\CS
Text Label 4350 1550 2    50   ~ 0
CLK\SCK
Text Label 4350 1650 2    50   ~ 0
CMD\MOSI
Text Label 4350 1750 2    50   ~ 0
DAT0\MISO
Wire Wire Line
	4550 1850 3950 1850
Wire Wire Line
	3950 1950 4000 1950
$Comp
L power:GND #PWR0136
U 1 1 5F920E19
P 4350 4400
F 0 "#PWR0136" H 4350 4150 50  0001 C CNN
F 1 "GND" H 4355 4227 50  0000 C CNN
F 2 "" H 4350 4400 50  0001 C CNN
F 3 "" H 4350 4400 50  0001 C CNN
	1    4350 4400
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male J12
U 1 1 5F8FD377
P 1950 2450
F 0 "J12" H 2058 2731 50  0000 C CNN
F 1 "OUT3" H 2058 2640 50  0000 C CNN
F 2 "DIY CONN:JST_XH_B3B-XH-A_1X03_P2.50mm_DIY" H 1950 2450 50  0001 C CNN
F 3 "~" H 1950 2450 50  0001 C CNN
	1    1950 2450
	1    0    0    -1  
$EndComp
Text Label 3350 1550 2    50   ~ 0
A_TRIG
Text Label 3350 1650 2    50   ~ 0
A_ECHO
Text Label 3350 2100 2    50   ~ 0
B_TRIG
Text Label 3350 2200 2    50   ~ 0
B_ECHO
Text Label 3350 2650 2    50   ~ 0
pH_TRIG
Text Label 3350 2750 2    50   ~ 0
pH_ECHO
$Comp
L Connector:Conn_01x03_Male J13
U 1 1 601877C7
P 650 1550
F 0 "J13" H 758 1831 50  0000 C CNN
F 1 "pH_SNS" H 758 1740 50  0000 C CNN
F 2 "DIY CONN:JST_XH_B3B-XH-A_1X03_P2.50mm_DIY" H 650 1550 50  0001 C CNN
F 3 "~" H 650 1550 50  0001 C CNN
	1    650  1550
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R1
U 1 1 601BB133
P 1200 1550
F 0 "R1" H 1259 1596 50  0000 L CNN
F 1 "5k1" H 1259 1505 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 1200 1550 50  0001 C CNN
F 3 "~" H 1200 1550 50  0001 C CNN
	1    1200 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R2
U 1 1 601BC650
P 1200 1850
F 0 "R2" H 1259 1896 50  0000 L CNN
F 1 "10k" H 1259 1805 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 1200 1850 50  0001 C CNN
F 3 "~" H 1200 1850 50  0001 C CNN
	1    1200 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	850  1650 1000 1650
Wire Wire Line
	1000 1650 1000 2050
$Comp
L power:GND #PWR0102
U 1 1 601C73C0
P 1000 2050
F 0 "#PWR0102" H 1000 1800 50  0001 C CNN
F 1 "GND" H 1005 1877 50  0000 C CNN
F 2 "" H 1000 2050 50  0001 C CNN
F 3 "" H 1000 2050 50  0001 C CNN
	1    1000 2050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 601C7DB4
P 1200 2050
F 0 "#PWR0103" H 1200 1800 50  0001 C CNN
F 1 "GND" H 1205 1877 50  0000 C CNN
F 2 "" H 1200 2050 50  0001 C CNN
F 3 "" H 1200 2050 50  0001 C CNN
	1    1200 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 2050 1200 1950
Text Label 1850 1700 2    50   ~ 0
pH_SNS
Wire Wire Line
	1200 1650 1200 1700
Connection ~ 1200 1700
Wire Wire Line
	1200 1700 1200 1750
Wire Wire Line
	850  1550 1000 1550
$Comp
L power:+5V #PWR0104
U 1 1 601FBD11
P 1000 1300
F 0 "#PWR0104" H 1000 1150 50  0001 C CNN
F 1 "+5V" H 1015 1473 50  0000 C CNN
F 2 "" H 1000 1300 50  0001 C CNN
F 3 "" H 1000 1300 50  0001 C CNN
	1    1000 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 1450 850  1450
Wire Wire Line
	850  3000 1000 3000
Wire Wire Line
	1000 3000 1000 3400
Wire Wire Line
	850  2900 1000 2900
Wire Wire Line
	1000 2500 1000 2900
$Comp
L Device:R_Small R15
U 1 1 5F8C6EE5
P 1500 2850
F 0 "R15" H 1559 2896 50  0000 L CNN
F 1 "4k7" H 1559 2805 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 1500 2850 50  0001 C CNN
F 3 "~" H 1500 2850 50  0001 C CNN
	1    1500 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 2950 1000 2950
Wire Wire Line
	1000 2950 1000 2900
Connection ~ 1000 2900
$Comp
L power:+5V #PWR0105
U 1 1 6022EC5F
P 1000 2500
F 0 "#PWR0105" H 1000 2350 50  0001 C CNN
F 1 "+5V" H 1015 2673 50  0000 C CNN
F 2 "" H 1000 2500 50  0001 C CNN
F 3 "" H 1000 2500 50  0001 C CNN
	1    1000 2500
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male J5
U 1 1 60233968
P 650 4100
F 0 "J5" H 758 4381 50  0000 C CNN
F 1 "pH_SNS" H 758 4290 50  0000 C CNN
F 2 "DIY CONN:JST_XH_B3B-XH-A_1X03_P2.50mm_DIY" H 650 4100 50  0001 C CNN
F 3 "~" H 650 4100 50  0001 C CNN
	1    650  4100
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R7
U 1 1 60233F65
P 1950 4250
F 0 "R7" H 2009 4296 50  0000 L CNN
F 1 "10k" H 2009 4205 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 1950 4250 50  0001 C CNN
F 3 "~" H 1950 4250 50  0001 C CNN
	1    1950 4250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 60243414
P 1000 4600
F 0 "#PWR0106" H 1000 4350 50  0001 C CNN
F 1 "GND" H 1005 4427 50  0000 C CNN
F 2 "" H 1000 4600 50  0001 C CNN
F 3 "" H 1000 4600 50  0001 C CNN
	1    1000 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	850  4200 1000 4200
Wire Wire Line
	1000 4200 1000 4600
$Comp
L power:+5V #PWR0113
U 1 1 60249B66
P 2650 3850
F 0 "#PWR0113" H 2650 3700 50  0001 C CNN
F 1 "+5V" H 2665 4023 50  0000 C CNN
F 2 "" H 2650 3850 50  0001 C CNN
F 3 "" H 2650 3850 50  0001 C CNN
	1    2650 3850
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1200 4000 850  4000
$Comp
L Device:R_Small R4
U 1 1 60251207
P 1200 4100
F 0 "R4" H 1259 4146 50  0000 L CNN
F 1 "5k1" H 1259 4055 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 1200 4100 50  0001 C CNN
F 3 "~" H 1200 4100 50  0001 C CNN
	1    1200 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R5
U 1 1 6025120D
P 1200 4400
F 0 "R5" H 1259 4446 50  0000 L CNN
F 1 "10k" H 1259 4355 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 1200 4400 50  0001 C CNN
F 3 "~" H 1200 4400 50  0001 C CNN
	1    1200 4400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0116
U 1 1 60251213
P 1200 4600
F 0 "#PWR0116" H 1200 4350 50  0001 C CNN
F 1 "GND" H 1205 4427 50  0000 C CNN
F 2 "" H 1200 4600 50  0001 C CNN
F 3 "" H 1200 4600 50  0001 C CNN
	1    1200 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 4600 1200 4500
Text Label 1850 4250 2    50   ~ 0
TDS_SNS
Wire Wire Line
	1200 4200 1200 4250
Connection ~ 1200 4250
Wire Wire Line
	1200 4250 1200 4300
$Comp
L power:GND #PWR0117
U 1 1 6027622C
P 1950 4600
F 0 "#PWR0117" H 1950 4350 50  0001 C CNN
F 1 "GND" H 1955 4427 50  0000 C CNN
F 2 "" H 1950 4600 50  0001 C CNN
F 3 "" H 1950 4600 50  0001 C CNN
	1    1950 4600
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1950 4350 1950 4600
Text Label 2900 4400 2    50   ~ 0
TD_SW
Connection ~ 1950 4100
Wire Wire Line
	1950 4100 1950 4150
$Comp
L Device:R_Small R9
U 1 1 60184D50
P 2500 4400
F 0 "R9" V 2304 4400 50  0000 C CNN
F 1 "200" V 2395 4400 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 2500 4400 50  0001 C CNN
F 3 "~" H 2500 4400 50  0001 C CNN
	1    2500 4400
	0    1    -1   0   
$EndComp
Wire Wire Line
	2600 4400 2900 4400
Wire Wire Line
	2400 4400 2300 4400
$Comp
L power:+12V #PWR0119
U 1 1 60199F35
P 4350 3950
F 0 "#PWR0119" H 4350 3800 50  0001 C CNN
F 1 "+12V" H 4365 4123 50  0000 C CNN
F 2 "" H 4350 3950 50  0001 C CNN
F 3 "" H 4350 3950 50  0001 C CNN
	1    4350 3950
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0120
U 1 1 601A1CE0
P 3650 3950
F 0 "#PWR0120" H 3650 3800 50  0001 C CNN
F 1 "+12V" H 3665 4123 50  0000 C CNN
F 2 "" H 3650 3950 50  0001 C CNN
F 3 "" H 3650 3950 50  0001 C CNN
	1    3650 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 3950 4350 4050
Wire Wire Line
	4350 4050 4450 4050
Wire Wire Line
	5150 4050 5250 4050
Wire Wire Line
	5250 3950 5250 4050
Wire Wire Line
	5150 4150 5250 4150
$Comp
L power:GND #PWR0124
U 1 1 601ED823
P 3650 4400
F 0 "#PWR0124" H 3650 4150 50  0001 C CNN
F 1 "GND" H 3655 4227 50  0000 C CNN
F 2 "" H 3650 4400 50  0001 C CNN
F 3 "" H 3650 4400 50  0001 C CNN
	1    3650 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 4100 3650 4100
Wire Wire Line
	3650 4100 3650 4200
Wire Wire Line
	3550 4200 3650 4200
Connection ~ 3650 4200
Wire Wire Line
	3650 4000 3550 4000
Wire Wire Line
	4350 4150 4450 4150
Wire Wire Line
	3650 4000 3650 3950
$Comp
L power:GND #PWR0129
U 1 1 6023C073
P 5600 4400
F 0 "#PWR0129" H 5600 4150 50  0001 C CNN
F 1 "GND" H 5605 4227 50  0000 C CNN
F 2 "" H 5600 4400 50  0001 C CNN
F 3 "" H 5600 4400 50  0001 C CNN
	1    5600 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 4150 5250 4400
Wire Wire Line
	4350 4150 4350 4400
Wire Wire Line
	3650 4200 3650 4400
Wire Wire Line
	3950 1750 4350 1750
Wire Wire Line
	3950 1650 4350 1650
Wire Wire Line
	3950 1550 4350 1550
Wire Wire Line
	3950 1450 4350 1450
Wire Wire Line
	3450 1300 3450 1450
Connection ~ 3450 1450
Wire Wire Line
	1000 1300 1000 1550
Wire Wire Line
	3400 2950 3400 2850
Connection ~ 3400 2850
Text Notes 1400 850  0    118  ~ 24
INPUT/OUTPUT
Wire Wire Line
	2150 2350 2350 2350
Wire Wire Line
	2350 1450 2150 1450
Wire Wire Line
	2150 1900 2350 1900
Wire Wire Line
	3000 2750 3350 2750
Wire Wire Line
	3000 2650 3350 2650
Wire Wire Line
	3000 2850 3400 2850
Wire Wire Line
	3000 2550 3450 2550
Wire Wire Line
	3000 2300 3400 2300
Wire Wire Line
	3000 2000 3450 2000
Wire Wire Line
	3000 1750 3400 1750
Wire Wire Line
	3000 1450 3450 1450
Wire Wire Line
	3000 1550 3350 1550
Wire Wire Line
	3000 1650 3350 1650
Wire Wire Line
	3000 2100 3350 2100
Wire Wire Line
	3000 2200 3350 2200
Wire Wire Line
	2450 1300 2450 1550
Wire Wire Line
	2400 1650 2400 2100
Wire Wire Line
	2150 2550 2400 2550
Connection ~ 2400 2550
Wire Wire Line
	2400 2550 2400 2650
Wire Wire Line
	2150 2450 2450 2450
Wire Wire Line
	2150 2100 2400 2100
Connection ~ 2400 2100
Wire Wire Line
	2400 2100 2400 2550
Wire Wire Line
	2150 2000 2450 2000
Connection ~ 2450 2000
Wire Wire Line
	2450 2000 2450 2450
Wire Wire Line
	2150 1650 2400 1650
Wire Wire Line
	2150 1550 2450 1550
Connection ~ 2450 1550
Wire Wire Line
	2450 1550 2450 2000
Wire Wire Line
	4000 4200 4000 4400
$Comp
L power:+12V #PWR0130
U 1 1 60535CC9
P 4000 3950
F 0 "#PWR0130" H 4000 3800 50  0001 C CNN
F 1 "+12V" H 4015 4123 50  0000 C CNN
F 2 "" H 4000 3950 50  0001 C CNN
F 3 "" H 4000 3950 50  0001 C CNN
	1    4000 3950
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NPN_ECB Q1
U 1 1 60546EB5
P 2300 4100
F 0 "Q1" V 2628 4100 50  0000 C CNN
F 1 "BD139" V 2537 4100 50  0000 C CNN
F 2 "TO Package DIY:TO-126-3_DIY" H 2500 4200 50  0001 C CNN
F 3 "~" H 2300 4100 50  0001 C CNN
	1    2300 4100
	0    1    -1   0   
$EndComp
Wire Wire Line
	2100 4000 1950 4000
Wire Wire Line
	1950 4000 1950 4100
Wire Wire Line
	2300 4300 2300 4400
Wire Wire Line
	2500 4000 2650 4000
Wire Wire Line
	2650 4000 2650 3850
Text Notes 3800 850  0    118  ~ 24
COMMUNICATION
Wire Wire Line
	4550 1300 4550 1850
Wire Wire Line
	5300 1300 5300 1550
Text Notes 4000 3550 0    118  ~ 24
POWER SUPPLY
Wire Wire Line
	5250 2000 5250 1450
Wire Wire Line
	4900 1750 5150 1750
Wire Wire Line
	4900 1650 5150 1650
Wire Wire Line
	5600 3950 5600 4000
Wire Wire Line
	5600 4200 5600 4400
$Comp
L Device:C_Small C1
U 1 1 601958BD
P 1500 1850
F 0 "C1" H 1592 1896 50  0000 L CNN
F 1 "104" H 1592 1805 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 1500 1850 50  0001 C CNN
F 3 "~" H 1500 1850 50  0001 C CNN
	1    1500 1850
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C4
U 1 1 6019616A
P 1500 4400
F 0 "C4" H 1592 4446 50  0000 L CNN
F 1 "104" H 1592 4355 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 1500 4400 50  0001 C CNN
F 3 "~" H 1500 4400 50  0001 C CNN
	1    1500 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 1750 1500 1700
Wire Wire Line
	1500 1700 1200 1700
$Comp
L power:GND #PWR0108
U 1 1 6019B9DE
P 1500 2050
F 0 "#PWR0108" H 1500 1800 50  0001 C CNN
F 1 "GND" H 1505 1877 50  0000 C CNN
F 2 "" H 1500 2050 50  0001 C CNN
F 3 "" H 1500 2050 50  0001 C CNN
	1    1500 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 2050 1500 1950
Wire Wire Line
	1500 4300 1500 4250
Wire Wire Line
	1500 4250 1200 4250
$Comp
L power:GND #PWR0109
U 1 1 601A54E0
P 1500 4600
F 0 "#PWR0109" H 1500 4350 50  0001 C CNN
F 1 "GND" H 1505 4427 50  0000 C CNN
F 2 "" H 1500 4600 50  0001 C CNN
F 3 "" H 1500 4600 50  0001 C CNN
	1    1500 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 4600 1500 4500
Wire Wire Line
	1500 1700 1850 1700
Connection ~ 1500 1700
Wire Wire Line
	1500 4250 1850 4250
Connection ~ 1500 4250
Wire Wire Line
	850  4100 1950 4100
Wire Wire Line
	7650 2800 7250 2800
$Comp
L power:+3V3 #PWR0107
U 1 1 606862D6
P 7650 2800
F 0 "#PWR0107" H 7650 2650 50  0001 C CNN
F 1 "+3V3" V 7665 2928 50  0000 L CNN
F 2 "" H 7650 2800 50  0001 C CNN
F 3 "" H 7650 2800 50  0001 C CNN
	1    7650 2800
	0    1    1    0   
$EndComp
Text Notes 5900 850  0    118  ~ 24
ESP32-DEVKIT-V1
Wire Wire Line
	5850 2800 6250 2800
Wire Wire Line
	5850 2700 6250 2700
Wire Wire Line
	5850 2600 6250 2600
Wire Wire Line
	5850 2500 6250 2500
Wire Wire Line
	5850 2400 6250 2400
Wire Wire Line
	5850 2300 6250 2300
Wire Wire Line
	5850 2200 6250 2200
Wire Wire Line
	5850 2100 6250 2100
Wire Wire Line
	5850 2000 6250 2000
Wire Wire Line
	5850 1900 6250 1900
Wire Wire Line
	5850 1800 6250 1800
Wire Wire Line
	5850 1700 6250 1700
Wire Wire Line
	7250 2700 7650 2700
Wire Wire Line
	7250 2600 7650 2600
Wire Wire Line
	7250 2500 7650 2500
Wire Wire Line
	7250 2400 7650 2400
Wire Wire Line
	7250 2100 7650 2100
Wire Wire Line
	7250 2000 7650 2000
Wire Wire Line
	7250 1900 7650 1900
Wire Wire Line
	7250 1800 7650 1800
Wire Wire Line
	7250 1500 7650 1500
Wire Wire Line
	7250 1400 7650 1400
Text Label 7650 2600 2    50   ~ 0
TD_SW
$Comp
L power:GND #PWR0101
U 1 1 601B4518
P 7650 2700
F 0 "#PWR0101" H 7650 2450 50  0001 C CNN
F 1 "GND" V 7655 2572 50  0000 R CNN
F 2 "" H 7650 2700 50  0001 C CNN
F 3 "" H 7650 2700 50  0001 C CNN
	1    7650 2700
	0    -1   -1   0   
$EndComp
Text Label 5850 1700 0    50   ~ 0
TDS_SNS
Text Label 5850 1800 0    50   ~ 0
pH_SNS
Text Label 7650 2500 2    50   ~ 0
pH_ECHO
Text Label 7650 2400 2    50   ~ 0
pH_TRIG
Text Label 5850 2300 0    50   ~ 0
B_ECHO
Text Label 5850 2200 0    50   ~ 0
B_TRIG
Text Label 5850 2100 0    50   ~ 0
A_ECHO
Text Label 5850 2000 0    50   ~ 0
A_TRIG
Text Label 5850 2600 0    50   ~ 0
OUT3
Text Label 5850 2500 0    50   ~ 0
OUT2
Text Label 5850 2400 0    50   ~ 0
OUT1
$Comp
L Mechanical:MountingHole H3
U 1 1 5FC89570
P 7000 3300
F 0 "H3" H 7100 3346 50  0000 L CNN
F 1 "Mounting" H 7100 3255 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad" H 7000 3300 50  0001 C CNN
F 3 "~" H 7000 3300 50  0001 C CNN
	1    7000 3300
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H4
U 1 1 5FC8938B
P 7000 3800
F 0 "H4" H 7100 3846 50  0000 L CNN
F 1 "Mounting" H 7100 3755 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad" H 7000 3800 50  0001 C CNN
F 3 "~" H 7000 3800 50  0001 C CNN
	1    7000 3800
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 5FC89120
P 6500 3800
F 0 "H2" H 6600 3846 50  0000 L CNN
F 1 "Mounting" H 6600 3755 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad" H 6500 3800 50  0001 C CNN
F 3 "~" H 6500 3800 50  0001 C CNN
	1    6500 3800
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H1
U 1 1 5FC88760
P 6500 3300
F 0 "H1" H 6600 3346 50  0000 L CNN
F 1 "Mounting" H 6600 3255 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad" H 6500 3300 50  0001 C CNN
F 3 "~" H 6500 3300 50  0001 C CNN
	1    6500 3300
	1    0    0    -1  
$EndComp
Text Label 7650 2100 2    50   ~ 0
DAT3\CS
Text Label 7650 2000 2    50   ~ 0
CLK\SCK
Text Label 7650 1900 2    50   ~ 0
DAT0\MISO
Text Label 7650 1400 2    50   ~ 0
CMD\MOSI
$Comp
L Device:CP_Small C2
U 1 1 5F8F6B3D
P 5600 4100
F 0 "C2" H 5688 4146 50  0000 L CNN
F 1 "47uf" H 5688 4055 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 5600 4100 50  0001 C CNN
F 3 "~" H 5600 4100 50  0001 C CNN
	1    5600 4100
	-1   0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0126
U 1 1 5F8CCD3F
P 5600 3950
F 0 "#PWR0126" H 5600 3800 50  0001 C CNN
F 1 "+5V" H 5615 4123 50  0000 C CNN
F 2 "" H 5600 3950 50  0001 C CNN
F 3 "" H 5600 3950 50  0001 C CNN
	1    5600 3950
	1    0    0    -1  
$EndComp
Text Label 7650 1800 2    50   ~ 0
SDA
Text Label 7650 1500 2    50   ~ 0
SCL
$Comp
L power:+5V #PWR0112
U 1 1 5F857FB4
P 5850 2800
F 0 "#PWR0112" H 5850 2650 50  0001 C CNN
F 1 "+5V" V 5865 2928 50  0000 L CNN
F 2 "" H 5850 2800 50  0001 C CNN
F 3 "" H 5850 2800 50  0001 C CNN
	1    5850 2800
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 5F856385
P 5850 2700
F 0 "#PWR0111" H 5850 2450 50  0001 C CNN
F 1 "GND" V 5855 2572 50  0000 R CNN
F 2 "" H 5850 2700 50  0001 C CNN
F 3 "" H 5850 2700 50  0001 C CNN
	1    5850 2700
	0    1    1    0   
$EndComp
Text Label 5850 1900 0    50   ~ 0
TEMP_SNS
$Comp
L ESP32~DevKit~V1.1:ESP32-DevKit_V1 U4
U 1 1 5F8108BD
P 6750 2100
F 0 "U4" H 6750 3065 50  0000 C CNN
F 1 "ESP32-DevKit_V1" H 6750 2974 50  0000 C CNN
F 2 "ESP32-DevKit_V1:ESP32-DevKit_V1" H 6650 2000 50  0001 C CNN
F 3 "" H 6650 2000 50  0001 C CNN
	1    6750 2100
	1    0    0    -1  
$EndComp
$EndSCHEMATC
