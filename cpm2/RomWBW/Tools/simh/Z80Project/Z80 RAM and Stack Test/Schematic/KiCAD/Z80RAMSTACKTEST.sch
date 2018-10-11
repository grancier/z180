EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:MCPARTS
EELAYER 27 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 1
Title ""
Date "5 apr 2015"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CY62256N U?
U 1 1 550A0662
P 7350 3850
F 0 "U?" H 7050 5000 60  0000 C CNN
F 1 "CY62256N" H 7350 3250 47  0000 C CNN
F 2 "~" H 7500 4050 60  0000 C CNN
F 3 "~" H 7500 4050 60  0000 C CNN
	1    7350 3850
	1    0    0    -1  
$EndComp
$Comp
L PC16550DN U?
U 1 1 550AF784
P 10300 7050
F 0 "U?" H 9800 8800 70  0000 C CNN
F 1 "PC16550DN" H 10300 7050 59  0000 C CNN
F 2 "~" H 10500 7150 60  0000 C CNN
F 3 "~" H 10500 7150 60  0000 C CNN
	1    10300 7050
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 550AF29B
P 2450 6350
F 0 "R?" V 2530 6350 40  0000 C CNN
F 1 "1K" V 2457 6351 40  0000 C CNN
F 2 "~" V 2380 6350 30  0000 C CNN
F 3 "~" H 2450 6350 30  0000 C CNN
	1    2450 6350
	1    0    0    -1  
$EndComp
$Comp
L DPST SW?
U 1 1 550AF2B4
P 1950 7000
F 0 "SW?" H 1950 7100 70  0000 C CNN
F 1 "DPST" H 1950 6900 70  0000 C CNN
F 2 "~" H 1950 7000 60  0000 C CNN
F 3 "~" H 1950 7000 60  0000 C CNN
	1    1950 7000
	-1   0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 550AF2FA
P 2450 6000
F 0 "#PWR?" H 2450 6100 30  0001 C CNN
F 1 "VCC" H 2450 6100 30  0000 C CNN
F 2 "" H 2450 6000 60  0000 C CNN
F 3 "" H 2450 6000 60  0000 C CNN
	1    2450 6000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 550AF31D
P 1300 7900
F 0 "#PWR?" H 1300 7900 30  0001 C CNN
F 1 "GND" H 1300 7830 30  0001 C CNN
F 2 "" H 1300 7900 60  0000 C CNN
F 3 "" H 1300 7900 60  0000 C CNN
	1    1300 7900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 550AF5A8
P 3950 7900
F 0 "#PWR?" H 3950 7900 30  0001 C CNN
F 1 "GND" H 3950 7830 30  0001 C CNN
F 2 "" H 3950 7900 60  0000 C CNN
F 3 "" H 3950 7900 60  0000 C CNN
	1    3950 7900
	1    0    0    -1  
$EndComp
Entry Wire Line
	6100 5300 6200 5400
Entry Wire Line
	6000 5400 6100 5300
Entry Wire Line
	6100 5400 6200 5500
Entry Wire Line
	6100 5500 6200 5600
Entry Wire Line
	6100 5600 6200 5700
Entry Wire Line
	6100 5700 6200 5800
Entry Wire Line
	6100 5800 6200 5900
Entry Wire Line
	6100 5900 6200 6000
Entry Wire Line
	6100 6000 6200 6100
Entry Wire Line
	6100 6100 6200 6200
Entry Wire Line
	6100 6200 6200 6300
Entry Wire Line
	6000 5500 6100 5400
Entry Wire Line
	6000 5600 6100 5500
Entry Wire Line
	6000 5700 6100 5600
Entry Wire Line
	6000 5800 6100 5700
Entry Wire Line
	6000 5900 6100 5800
Entry Wire Line
	6000 6000 6100 5900
Entry Wire Line
	6000 6100 6100 6000
Entry Wire Line
	6000 6200 6100 6100
Entry Wire Line
	6000 6300 6100 6200
Entry Wire Line
	6100 6300 6200 6400
Text Label 6100 4650 1    60   ~ 0
ADDRESS BUS
Text Label 8700 3750 3    60   ~ 0
DATA BUS
Entry Wire Line
	6100 2950 6200 2850
Entry Wire Line
	6100 3050 6200 2950
Entry Wire Line
	6100 3150 6200 3050
Entry Wire Line
	6100 3250 6200 3150
Entry Wire Line
	6100 3350 6200 3250
Entry Wire Line
	6100 3450 6200 3350
Entry Wire Line
	6100 3550 6200 3450
Entry Wire Line
	6100 3650 6200 3550
Entry Wire Line
	6100 3750 6200 3650
Entry Wire Line
	6100 3850 6200 3750
Entry Wire Line
	8850 6450 8950 6550
Entry Wire Line
	8850 6350 8950 6450
Entry Wire Line
	8850 6250 8950 6350
Entry Wire Line
	6000 7100 6100 7200
Entry Wire Line
	6000 7200 6100 7300
Entry Wire Line
	6000 7300 6100 7400
Entry Wire Line
	6000 7400 6100 7500
Entry Wire Line
	6000 7500 6100 7600
Entry Wire Line
	6000 7600 6100 7700
Entry Wire Line
	6000 7700 6100 7800
Entry Wire Line
	6000 7800 6100 7900
Text Label 7150 8050 0    60   ~ 0
DATA BUS
Text Label 7700 5100 2    60   ~ 0
ADDRESS BUS
Entry Wire Line
	8600 5400 8700 5500
Entry Wire Line
	8600 5500 8700 5600
Entry Wire Line
	8600 5600 8700 5700
Entry Wire Line
	8600 5700 8700 5800
Entry Wire Line
	8600 5800 8700 5900
Entry Wire Line
	8600 5900 8700 6000
Entry Wire Line
	8600 6000 8700 6100
Entry Wire Line
	8600 6100 8700 6200
Entry Wire Line
	8600 2850 8700 2950
Entry Wire Line
	8600 2950 8700 3050
Entry Wire Line
	8600 3050 8700 3150
Entry Wire Line
	8600 3150 8700 3250
Entry Wire Line
	8600 3250 8700 3350
Entry Wire Line
	8600 3350 8700 3450
Entry Wire Line
	8600 3450 8700 3550
Entry Wire Line
	8600 3550 8700 3650
Entry Wire Line
	9200 5350 9300 5450
Entry Wire Line
	9200 5450 9300 5550
Entry Wire Line
	9200 5550 9300 5650
Entry Wire Line
	9200 5650 9300 5750
Entry Wire Line
	9200 5750 9300 5850
Entry Wire Line
	9200 5850 9300 5950
Entry Wire Line
	9200 5950 9300 6050
Entry Wire Line
	9200 6050 9300 6150
Text Label 9200 4500 3    60   ~ 0
DATA BUS
Entry Bus Bus
	9100 4250 9200 4350
Entry Bus Bus
	6100 5000 6200 5100
$Comp
L VCC #PWR?
U 1 1 550B0E99
P 3950 7550
F 0 "#PWR?" H 3950 7650 30  0001 C CNN
F 1 "VCC" H 3950 7650 30  0000 C CNN
F 2 "" H 3950 7550 60  0000 C CNN
F 3 "" H 3950 7550 60  0000 C CNN
	1    3950 7550
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 550B0EFD
P 6600 4600
F 0 "#PWR?" H 6600 4700 30  0001 C CNN
F 1 "VCC" H 6600 4700 30  0000 C CNN
F 2 "" H 6600 4600 60  0000 C CNN
F 3 "" H 6600 4600 60  0000 C CNN
	1    6600 4600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 550B0F03
P 6600 4950
F 0 "#PWR?" H 6600 4950 30  0001 C CNN
F 1 "GND" H 6600 4880 30  0001 C CNN
F 2 "" H 6600 4950 60  0000 C CNN
F 3 "" H 6600 4950 60  0000 C CNN
	1    6600 4950
	1    0    0    -1  
$EndComp
Text Label 4000 6800 0    60   ~ 0
~MR
$Comp
L 74LS14 U?
U 2 1 550B1CE8
P 3050 7200
F 0 "U?" H 3200 7300 40  0000 C CNN
F 1 "74LS14" H 3250 7100 40  0000 C CNN
F 2 "~" H 3050 7200 60  0000 C CNN
F 3 "~" H 3050 7200 60  0000 C CNN
	2    3050 7200
	1    0    0    -1  
$EndComp
Text Label 3600 7000 0    60   ~ 0
MR
Text Label 9300 5450 0    60   ~ 0
D0
Text Label 9300 5550 0    60   ~ 0
D1
Text Label 9300 5650 0    60   ~ 0
D2
Text Label 9300 5750 0    60   ~ 0
D3
Text Label 9300 5850 0    60   ~ 0
D4
Text Label 9300 5950 0    60   ~ 0
D5
Text Label 9300 6050 0    60   ~ 0
D6
Text Label 9300 6150 0    60   ~ 0
D7
Text Label 8050 5400 0    60   ~ 0
D0
Text Label 8050 5500 0    60   ~ 0
D1
Text Label 8050 5600 0    60   ~ 0
D2
Text Label 8050 5700 0    60   ~ 0
D3
Text Label 8050 5800 0    60   ~ 0
D4
Text Label 8050 5900 0    60   ~ 0
D5
Text Label 8050 6000 0    60   ~ 0
D6
Text Label 8050 6100 0    60   ~ 0
D7
Text Label 6500 2850 0    60   ~ 0
A0
Text Label 6500 2950 0    60   ~ 0
A1
Text Label 6500 3050 0    60   ~ 0
A2
Text Label 6500 3150 0    60   ~ 0
A3
Text Label 6500 3250 0    60   ~ 0
A4
Text Label 6500 3350 0    60   ~ 0
A5
Text Label 6500 3450 0    60   ~ 0
A6
Text Label 6500 3550 0    60   ~ 0
A7
Text Label 6500 3650 0    60   ~ 0
A8
Text Label 6500 3750 0    60   ~ 0
A9
Text Label 6500 3850 0    60   ~ 0
A10
Text Label 6500 5400 0    60   ~ 0
A0
Text Label 6500 5500 0    60   ~ 0
A1
Text Label 6500 5600 0    60   ~ 0
A2
Text Label 6500 5700 0    60   ~ 0
A3
Text Label 6500 5800 0    60   ~ 0
A4
Text Label 6500 5900 0    60   ~ 0
A5
Text Label 6500 6000 0    60   ~ 0
A6
Text Label 6500 6100 0    60   ~ 0
A7
Text Label 6500 6200 0    60   ~ 0
A8
Text Label 6500 6300 0    60   ~ 0
A9
Text Label 6500 6400 0    60   ~ 0
A10
Text Label 5550 7100 0    60   ~ 0
D0
Text Label 5550 7200 0    60   ~ 0
D1
Text Label 5550 7300 0    60   ~ 0
D2
Text Label 5550 7400 0    60   ~ 0
D3
Text Label 5550 7500 0    60   ~ 0
D4
Text Label 5550 7600 0    60   ~ 0
D5
Text Label 5550 7700 0    60   ~ 0
D6
Text Label 5550 7800 0    60   ~ 0
D7
Text Label 9300 6350 0    60   ~ 0
A0
Text Label 9300 6450 0    60   ~ 0
A1
Text Label 9300 6550 0    60   ~ 0
A2
Text Label 5550 5400 0    60   ~ 0
A0
Text Label 5550 5500 0    60   ~ 0
A1
Text Label 5550 5600 0    60   ~ 0
A2
Text Label 5550 5700 0    60   ~ 0
A3
Text Label 5550 5800 0    60   ~ 0
A4
Text Label 5550 5900 0    60   ~ 0
A5
Text Label 5550 6000 0    60   ~ 0
A6
Text Label 5550 6100 0    60   ~ 0
A7
Text Label 5550 6200 0    60   ~ 0
A8
Text Label 5550 6300 0    60   ~ 0
A9
Text Label 5550 6400 0    60   ~ 0
A10
Text Label 3900 7350 0    60   ~ 0
CLK
$Comp
L VCC #PWR?
U 1 1 550B24C8
P 6600 7100
F 0 "#PWR?" H 6600 7200 30  0001 C CNN
F 1 "VCC" H 6600 7200 30  0000 C CNN
F 2 "" H 6600 7100 60  0000 C CNN
F 3 "" H 6600 7100 60  0000 C CNN
	1    6600 7100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 550B24CE
P 6600 7500
F 0 "#PWR?" H 6600 7500 30  0001 C CNN
F 1 "GND" H 6600 7430 30  0001 C CNN
F 2 "" H 6600 7500 60  0000 C CNN
F 3 "" H 6600 7500 60  0000 C CNN
	1    6600 7500
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 550B270B
P 9350 8450
F 0 "#PWR?" H 9350 8550 30  0001 C CNN
F 1 "VCC" H 9350 8550 30  0000 C CNN
F 2 "" H 9350 8450 60  0000 C CNN
F 3 "" H 9350 8450 60  0000 C CNN
	1    9350 8450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 550B2711
P 9350 8800
F 0 "#PWR?" H 9350 8800 30  0001 C CNN
F 1 "GND" H 9350 8730 30  0001 C CNN
F 2 "" H 9350 8800 60  0000 C CNN
F 3 "" H 9350 8800 60  0000 C CNN
	1    9350 8800
	1    0    0    -1  
$EndComp
Text Label 9300 8300 0    60   ~ 0
MR
Text Label 8050 2850 0    60   ~ 0
D0
Text Label 8050 2950 0    60   ~ 0
D1
Text Label 8050 3050 0    60   ~ 0
D2
Text Label 8050 3150 0    60   ~ 0
D3
Text Label 8050 3250 0    60   ~ 0
D4
Text Label 8050 3350 0    60   ~ 0
D5
Text Label 8050 3450 0    60   ~ 0
D6
Text Label 8050 3550 0    60   ~ 0
D7
Text Label 8350 7200 2    60   ~ 0
ROMCS
Text Label 8350 7300 2    60   ~ 0
MEMRD
Text Label 8350 4650 2    60   ~ 0
RAMCS
Text Label 8350 4750 2    60   ~ 0
MEMRD
Text Label 8350 4850 2    60   ~ 0
MEMWR
Entry Wire Line
	6100 3950 6200 3850
$Comp
L Z80CPU U?
U 1 1 550AF57F
P 4800 6700
F 0 "U?" H 4400 8150 50  0000 C CNN
F 1 "Z80CPU" H 4800 6750 50  0000 C CNN
F 2 "~" H 4800 6700 50  0001 C CNN
F 3 "~" H 4800 6700 50  0001 C CNN
	1    4800 6700
	1    0    0    -1  
$EndComp
$Comp
L CAT28C256 U?
U 1 1 55086ED5
P 7350 6400
F 0 "U?" H 7050 7550 60  0000 C CNN
F 1 "CAT28C256" H 7350 5800 47  0000 C CNN
F 2 "" H 7500 6600 60  0000 C CNN
F 3 "" H 7500 6600 60  0000 C CNN
	1    7350 6400
	1    0    0    -1  
$EndComp
$Comp
L 74LS32 U?
U 1 1 550B3D1C
P 4800 3200
F 0 "U?" H 4800 3250 60  0000 C CNN
F 1 "74LS32" H 4800 3150 60  0000 C CNN
F 2 "~" H 4800 3200 60  0000 C CNN
F 3 "~" H 4800 3200 60  0000 C CNN
	1    4800 3200
	1    0    0    -1  
$EndComp
$Comp
L 74LS32 U?
U 2 1 550B3D29
P 4800 3700
F 0 "U?" H 4800 3750 60  0000 C CNN
F 1 "74LS32" H 4800 3650 60  0000 C CNN
F 2 "~" H 4800 3700 60  0000 C CNN
F 3 "~" H 4800 3700 60  0000 C CNN
	2    4800 3700
	1    0    0    -1  
$EndComp
Text Label 3850 3450 2    60   ~ 0
~MREQ
Text Label 4050 5500 2    60   ~ 0
~MREQ
Text Label 4050 5700 2    60   ~ 0
~RD
Text Label 4050 5800 2    60   ~ 0
~WR
Text Label 4200 3100 2    60   ~ 0
~RD
Text Label 4200 3800 2    60   ~ 0
~WR
Text Label 5400 3200 0    60   ~ 0
MEMRD
Text Label 5400 3700 0    60   ~ 0
MEMWR
$Comp
L VCC #PWR?
U 1 1 550B3E39
P 8450 7400
F 0 "#PWR?" H 8450 7500 30  0001 C CNN
F 1 "VCC" H 8450 7500 30  0000 C CNN
F 2 "" H 8450 7400 60  0000 C CNN
F 3 "" H 8450 7400 60  0000 C CNN
	1    8450 7400
	1    0    0    -1  
$EndComp
$Comp
L 74LS32 U?
U 3 1 550B3E7D
P 4800 4250
F 0 "U?" H 4800 4300 60  0000 C CNN
F 1 "74LS32" H 4800 4200 60  0000 C CNN
F 2 "~" H 4800 4250 60  0000 C CNN
F 3 "~" H 4800 4250 60  0000 C CNN
	3    4800 4250
	1    0    0    -1  
$EndComp
$Comp
L 74LS32 U?
U 4 1 550B3E83
P 4800 4750
F 0 "U?" H 4800 4800 60  0000 C CNN
F 1 "74LS32" H 4800 4700 60  0000 C CNN
F 2 "~" H 4800 4750 60  0000 C CNN
F 3 "~" H 4800 4750 60  0000 C CNN
	4    4800 4750
	1    0    0    -1  
$EndComp
Text Label 3850 4500 2    60   ~ 0
~MREQ
Text Label 5400 4250 0    60   ~ 0
ROMCS
Text Label 5400 4750 0    60   ~ 0
RAMCS
Text Label 4200 4150 2    60   ~ 0
A15
Text Label 4200 4850 2    60   ~ 0
~A15
$Comp
L 74LS14 U?
U 1 1 550B3E96
P 4750 2650
F 0 "U?" H 4900 2750 40  0000 C CNN
F 1 "74LS14" H 4950 2550 40  0000 C CNN
F 2 "~" H 4750 2650 60  0000 C CNN
F 3 "~" H 4750 2650 60  0000 C CNN
	1    4750 2650
	1    0    0    -1  
$EndComp
Text Label 4300 2650 2    60   ~ 0
A15
Text Label 5200 2650 0    60   ~ 0
~A15
$Comp
L 74LS32 U?
U 1 1 550B31D5
P 2550 3150
F 0 "U?" H 2550 3200 60  0000 C CNN
F 1 "74LS32" H 2550 3100 60  0000 C CNN
F 2 "~" H 2550 3150 60  0000 C CNN
F 3 "~" H 2550 3150 60  0000 C CNN
	1    2550 3150
	1    0    0    -1  
$EndComp
$Comp
L 74LS32 U?
U 2 1 550B31DB
P 2550 3650
F 0 "U?" H 2550 3700 60  0000 C CNN
F 1 "74LS32" H 2550 3600 60  0000 C CNN
F 2 "~" H 2550 3650 60  0000 C CNN
F 3 "~" H 2550 3650 60  0000 C CNN
	2    2550 3650
	1    0    0    -1  
$EndComp
Text Label 1600 3400 2    60   ~ 0
~IORQ
Text Label 1950 3050 2    60   ~ 0
~RD
Text Label 1950 3750 2    60   ~ 0
~WR
Text Label 3150 3150 0    60   ~ 0
IORD
Text Label 3150 3650 0    60   ~ 0
IOWR
Text Label 9450 7600 2    60   ~ 0
IORD
Text Label 9450 7500 2    60   ~ 0
IOWR
$Comp
L VCC #PWR?
U 1 1 550B3380
P 9350 6700
F 0 "#PWR?" H 9350 6800 30  0001 C CNN
F 1 "VCC" H 9350 6800 30  0000 C CNN
F 2 "" H 9350 6700 60  0000 C CNN
F 3 "" H 9350 6700 60  0000 C CNN
	1    9350 6700
	1    0    0    -1  
$EndComp
Text Label 9450 7000 2    60   ~ 0
IOCS0
NoConn ~ 9450 7300
$Comp
L GND #PWR?
U 1 1 550B378E
P 9250 8150
F 0 "#PWR?" H 9250 8150 30  0001 C CNN
F 1 "GND" H 9250 8080 30  0001 C CNN
F 2 "" H 9250 8150 60  0000 C CNN
F 3 "" H 9250 8150 60  0000 C CNN
	1    9250 8150
	1    0    0    -1  
$EndComp
Text Label 1850 4400 2    60   ~ 0
A7
Text Label 1850 4300 2    60   ~ 0
A6
Text Label 1850 4200 2    60   ~ 0
A5
Text Label 3050 4200 0    60   ~ 0
IOCS0
Text Label 3050 4300 0    60   ~ 0
IOCS1
Text Label 3050 4400 0    60   ~ 0
IOCS2
Text Label 3050 4500 0    60   ~ 0
IOCS3
Text Label 3050 4600 0    60   ~ 0
IOCS4
Text Label 3050 4700 0    60   ~ 0
IOCS5
Text Label 3050 4800 0    60   ~ 0
IOCS6
Text Label 3050 4900 0    60   ~ 0
IOCS7
Text Label 1550 4800 0    60   ~ 0
~IORQ
NoConn ~ 11150 6350
NoConn ~ 11150 6450
NoConn ~ 11150 6550
NoConn ~ 11150 6650
NoConn ~ 11150 7450
NoConn ~ 11150 7550
NoConn ~ 11150 7750
$Comp
L 74LS138 U?
U 1 1 550D74FD
P 2450 4550
F 0 "U?" H 2550 5050 60  0000 C CNN
F 1 "74LS138" H 2600 4001 60  0000 C CNN
F 2 "~" H 2450 4550 60  0000 C CNN
F 3 "~" H 2450 4550 60  0000 C CNN
	1    2450 4550
	1    0    0    -1  
$EndComp
Text Label 4050 5600 2    60   ~ 0
~IORQ
NoConn ~ 4050 6000
NoConn ~ 4050 5400
NoConn ~ 4050 7100
$Comp
L VCC #PWR?
U 1 1 550D7F7E
P 3850 6050
F 0 "#PWR?" H 3850 6150 30  0001 C CNN
F 1 "VCC" H 3850 6150 30  0000 C CNN
F 2 "" H 3850 6050 60  0000 C CNN
F 3 "" H 3850 6050 60  0000 C CNN
	1    3850 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 6100 2450 6000
Wire Wire Line
	4050 6800 2450 6800
Wire Wire Line
	2450 6800 2450 6600
Wire Wire Line
	1450 6800 1300 6800
Wire Wire Line
	1300 6800 1300 7900
Wire Wire Line
	1300 7200 1450 7200
Connection ~ 1300 7200
Wire Wire Line
	4050 7800 3950 7800
Wire Wire Line
	3950 7800 3950 7900
Wire Wire Line
	5550 5400 6000 5400
Wire Wire Line
	5550 5500 6000 5500
Wire Wire Line
	5550 5600 6000 5600
Wire Wire Line
	5550 5700 6000 5700
Wire Wire Line
	5550 5800 6000 5800
Wire Wire Line
	5550 5900 6000 5900
Wire Wire Line
	5550 6000 6000 6000
Wire Wire Line
	5550 6100 6000 6100
Wire Wire Line
	5550 6200 6000 6200
Wire Wire Line
	6000 6300 5550 6300
Wire Wire Line
	5550 6400 6000 6400
Wire Wire Line
	6200 5400 6700 5400
Wire Wire Line
	6700 5500 6200 5500
Wire Wire Line
	6200 5600 6700 5600
Wire Wire Line
	6700 5700 6200 5700
Wire Wire Line
	6200 5800 6700 5800
Wire Wire Line
	6700 5900 6200 5900
Wire Wire Line
	6200 6000 6700 6000
Wire Wire Line
	6700 6100 6200 6100
Wire Wire Line
	6200 6200 6700 6200
Wire Wire Line
	6200 6300 6700 6300
Wire Wire Line
	6700 6400 6200 6400
Wire Bus Line
	6100 7200 6100 8050
Wire Bus Line
	8700 8050 6100 8050
Wire Bus Line
	8700 2950 8700 8050
Wire Wire Line
	6200 2850 6700 2850
Wire Wire Line
	6700 2950 6200 2950
Wire Wire Line
	6200 3050 6700 3050
Wire Wire Line
	6700 3150 6200 3150
Wire Wire Line
	6200 3250 6700 3250
Wire Wire Line
	6700 3350 6200 3350
Wire Wire Line
	6200 3450 6700 3450
Wire Wire Line
	6700 3550 6200 3550
Wire Wire Line
	6200 3650 6700 3650
Wire Wire Line
	6700 3750 6200 3750
Wire Wire Line
	8950 6350 9450 6350
Wire Wire Line
	9450 6450 8950 6450
Wire Wire Line
	8950 6550 9450 6550
Wire Bus Line
	8850 5100 8850 6450
Wire Wire Line
	5550 7800 6000 7800
Wire Wire Line
	6000 7700 5550 7700
Wire Wire Line
	5550 7600 6000 7600
Wire Wire Line
	6000 7500 5550 7500
Wire Wire Line
	5550 7400 6000 7400
Wire Wire Line
	6000 7300 5550 7300
Wire Wire Line
	5550 7200 6000 7200
Wire Wire Line
	6000 7100 5550 7100
Wire Wire Line
	8050 5400 8600 5400
Wire Wire Line
	8600 5500 8050 5500
Wire Wire Line
	8050 5600 8600 5600
Wire Wire Line
	8600 5700 8050 5700
Wire Wire Line
	8050 5800 8600 5800
Wire Wire Line
	8600 5900 8050 5900
Wire Wire Line
	8050 6000 8600 6000
Wire Wire Line
	8050 6100 8600 6100
Wire Wire Line
	8050 2850 8600 2850
Wire Wire Line
	8600 2950 8050 2950
Wire Wire Line
	8050 3050 8600 3050
Wire Wire Line
	8600 3150 8050 3150
Wire Wire Line
	8050 3250 8600 3250
Wire Wire Line
	8600 3350 8050 3350
Wire Wire Line
	8050 3450 8600 3450
Wire Wire Line
	8600 3550 8050 3550
Wire Bus Line
	9200 4350 9200 6050
Wire Wire Line
	9300 5450 9450 5450
Wire Wire Line
	9450 5550 9300 5550
Wire Wire Line
	9300 5650 9450 5650
Wire Wire Line
	9450 5750 9300 5750
Wire Wire Line
	9300 5850 9450 5850
Wire Wire Line
	9450 5950 9300 5950
Wire Wire Line
	9300 6050 9450 6050
Wire Wire Line
	9450 6150 9300 6150
Wire Bus Line
	9100 4250 8700 4250
Wire Bus Line
	8700 4250 8700 4200
Wire Bus Line
	6200 5100 8850 5100
Wire Wire Line
	11150 8150 11300 8150
Wire Wire Line
	11300 8150 11300 8350
Wire Wire Line
	11300 8350 11150 8350
Wire Wire Line
	4050 7600 3950 7600
Wire Wire Line
	3950 7600 3950 7550
Wire Wire Line
	6700 4650 6600 4650
Wire Wire Line
	6600 4650 6600 4600
Wire Wire Line
	6700 4850 6600 4850
Wire Wire Line
	6600 4850 6600 4950
Wire Wire Line
	6200 3850 6700 3850
Wire Wire Line
	4050 7350 3800 7350
Wire Wire Line
	3800 7350 3800 8350
Wire Wire Line
	2450 7200 2600 7200
Wire Wire Line
	3500 7200 3600 7200
Wire Wire Line
	3600 7200 3600 7000
Wire Wire Line
	6700 7200 6600 7200
Wire Wire Line
	6600 7200 6600 7100
Wire Wire Line
	6700 7400 6600 7400
Wire Wire Line
	6600 7400 6600 7500
Wire Wire Line
	9450 8500 9350 8500
Wire Wire Line
	9350 8500 9350 8450
Wire Wire Line
	9450 8700 9350 8700
Wire Wire Line
	9350 8700 9350 8800
Wire Wire Line
	9450 8300 9300 8300
Wire Wire Line
	8050 7200 8350 7200
Wire Wire Line
	8050 7300 8350 7300
Wire Wire Line
	8050 7400 8450 7400
Wire Wire Line
	8050 4650 8350 4650
Wire Wire Line
	8050 4750 8350 4750
Wire Wire Line
	8050 4850 8350 4850
Wire Wire Line
	4200 3300 4200 3600
Wire Wire Line
	4200 3450 3850 3450
Connection ~ 4200 3450
Wire Wire Line
	4200 4350 4200 4650
Wire Wire Line
	4200 4500 3850 4500
Connection ~ 4200 4500
Wire Wire Line
	1950 3250 1950 3550
Wire Wire Line
	1950 3400 1600 3400
Connection ~ 1950 3400
Wire Wire Line
	9450 7800 9250 7800
Wire Wire Line
	9250 7800 9250 8150
Wire Wire Line
	9450 7900 9250 7900
Connection ~ 9250 7900
Wire Wire Line
	9450 6800 9350 6800
Wire Wire Line
	9350 6700 9350 6900
Wire Wire Line
	9350 6900 9450 6900
Connection ~ 9350 6800
Wire Wire Line
	9250 8100 9450 8100
Connection ~ 9250 8100
Wire Wire Line
	3850 6050 3850 6600
Wire Wire Line
	3850 6150 4050 6150
Wire Wire Line
	3850 6300 4050 6300
Connection ~ 3850 6150
Wire Wire Line
	3850 6500 4050 6500
Connection ~ 3850 6300
Wire Wire Line
	3850 6600 4050 6600
Connection ~ 3850 6500
Wire Wire Line
	11150 7250 11650 7250
Wire Wire Line
	11450 7150 11450 8000
Wire Wire Line
	11450 7150 11150 7150
$Comp
L CAP C?
U 1 1 551C4C38
P 10250 3450
F 0 "C?" H 10250 3550 40  0000 L CNN
F 1 "100nF" H 10256 3365 40  0000 L CNN
F 2 "~" H 10288 3300 30  0000 C CNN
F 3 "~" H 10250 3450 60  0000 C CNN
	1    10250 3450
	1    0    0    -1  
$EndComp
$Comp
L CAP C?
U 1 1 551C4C3E
P 9950 3450
F 0 "C?" H 9950 3550 40  0000 L CNN
F 1 "10uF" H 9956 3365 40  0000 L CNN
F 2 "~" H 9988 3300 30  0000 C CNN
F 3 "~" H 9950 3450 60  0000 C CNN
	1    9950 3450
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 551C4C44
P 9650 3200
F 0 "#PWR?" H 9650 3300 30  0001 C CNN
F 1 "VCC" H 9650 3300 30  0000 C CNN
F 2 "" H 9650 3200 60  0000 C CNN
F 3 "" H 9650 3200 60  0000 C CNN
	1    9650 3200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 551C4C4A
P 9650 3700
F 0 "#PWR?" H 9650 3700 30  0001 C CNN
F 1 "GND" H 9650 3630 30  0001 C CNN
F 2 "" H 9650 3700 60  0000 C CNN
F 3 "" H 9650 3700 60  0000 C CNN
	1    9650 3700
	1    0    0    -1  
$EndComp
$Comp
L CAP C?
U 1 1 551C4C50
P 10550 3450
F 0 "C?" H 10550 3550 40  0000 L CNN
F 1 "100nF" H 10556 3365 40  0000 L CNN
F 2 "~" H 10588 3300 30  0000 C CNN
F 3 "~" H 10550 3450 60  0000 C CNN
	1    10550 3450
	1    0    0    -1  
$EndComp
$Comp
L CAP C?
U 1 1 551C4C56
P 10850 3450
F 0 "C?" H 10850 3550 40  0000 L CNN
F 1 "100nF" H 10856 3365 40  0000 L CNN
F 2 "~" H 10888 3300 30  0000 C CNN
F 3 "~" H 10850 3450 60  0000 C CNN
	1    10850 3450
	1    0    0    -1  
$EndComp
$Comp
L CAP C?
U 1 1 551C4C5C
P 11150 3450
F 0 "C?" H 11150 3550 40  0000 L CNN
F 1 "100nF" H 11156 3365 40  0000 L CNN
F 2 "~" H 11188 3300 30  0000 C CNN
F 3 "~" H 11150 3450 60  0000 C CNN
	1    11150 3450
	1    0    0    -1  
$EndComp
$Comp
L CAP C?
U 1 1 551C4C62
P 11450 3450
F 0 "C?" H 11450 3550 40  0000 L CNN
F 1 "100nF" H 11456 3365 40  0000 L CNN
F 2 "~" H 11488 3300 30  0000 C CNN
F 3 "~" H 11450 3450 60  0000 C CNN
	1    11450 3450
	1    0    0    -1  
$EndComp
$Comp
L CAP C?
U 1 1 551C4C68
P 11750 3450
F 0 "C?" H 11750 3550 40  0000 L CNN
F 1 "100nF" H 11756 3365 40  0000 L CNN
F 2 "~" H 11788 3300 30  0000 C CNN
F 3 "~" H 11750 3450 60  0000 C CNN
	1    11750 3450
	1    0    0    -1  
$EndComp
Text Notes 10250 3100 0    60   ~ 0
Tank + Decoupling Caps
Wire Wire Line
	9650 3700 9650 3650
Wire Wire Line
	9650 3650 11750 3650
Wire Wire Line
	9650 3200 9650 3250
Wire Wire Line
	9650 3250 11750 3250
Text Notes 9800 3750 0    24   ~ 0
Near \nPower Supply\nBetween\nVCC and GND
Text Notes 10150 3750 0    24   ~ 0
Across \nSW1\nPin 1 & 3
Text Notes 10500 3750 0    24   ~ 0
Near \nU1\nPin 11
Text Notes 10800 3750 0    24   ~ 0
Near \nU2 \nPIN 28
Text Notes 11100 3750 0    24   ~ 0
Near \nU3\nPin 40
Text Notes 11400 3750 0    24   ~ 0
Near \nU4\nPin 9
Text Notes 11700 3750 0    24   ~ 0
Across\nX1\nPIN 7 & 14\n
Text Notes 10250 3150 0    24   ~ 0
Electrolytic
Text Notes 10750 3150 0    24   ~ 0
Ceramic
$Comp
L MAX237 U?
U 1 1 551C5197
P 12450 7050
F 0 "U?" H 12000 8200 70  0000 C CNN
F 1 "MAX237" H 12450 7850 70  0000 C CNN
F 2 "" H 12450 7050 60  0000 C CNN
F 3 "" H 12450 7050 60  0000 C CNN
	1    12450 7050
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 551C519D
P 13550 5900
F 0 "#PWR?" H 13550 6000 30  0001 C CNN
F 1 "VCC" H 13550 6000 30  0000 C CNN
F 2 "" H 13550 5900 60  0000 C CNN
F 3 "" H 13550 5900 60  0000 C CNN
	1    13550 5900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 551C51A3
P 13600 6650
F 0 "#PWR?" H 13600 6650 30  0001 C CNN
F 1 "GND" H 13600 6580 30  0001 C CNN
F 2 "" H 13600 6650 60  0000 C CNN
F 3 "" H 13600 6650 60  0000 C CNN
	1    13600 6650
	1    0    0    -1  
$EndComp
$Comp
L DB9 J?
U 1 1 551C51AA
P 14400 7800
F 0 "J?" H 14400 8350 70  0000 C CNN
F 1 "DB9" H 14400 7250 70  0000 C CNN
F 2 "" H 14400 7800 60  0000 C CNN
F 3 "" H 14400 7800 60  0000 C CNN
F 4 "Serial Connector" H 14000 8500 79  0000 C CNN "Part Description"
	1    14400 7800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 551C51B0
P 14050 7250
F 0 "#PWR?" H 14050 7250 30  0001 C CNN
F 1 "GND" H 14050 7180 30  0001 C CNN
F 2 "" H 14050 7250 60  0000 C CNN
F 3 "" H 14050 7250 60  0000 C CNN
	1    14050 7250
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 551C51B6
P 13300 8300
F 0 "#PWR?" H 13300 8300 30  0001 C CNN
F 1 "GND" H 13300 8230 30  0001 C CNN
F 2 "" H 13300 8300 60  0000 C CNN
F 3 "" H 13300 8300 60  0000 C CNN
	1    13300 8300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 551C51BC
P 11550 7750
F 0 "#PWR?" H 11550 7750 30  0001 C CNN
F 1 "GND" H 11550 7680 30  0001 C CNN
F 2 "" H 11550 7750 60  0000 C CNN
F 3 "" H 11550 7750 60  0000 C CNN
	1    11550 7750
	1    0    0    -1  
$EndComp
NoConn ~ 13250 7450
NoConn ~ 13250 7550
NoConn ~ 13250 7650
NoConn ~ 11650 8200
$Comp
L CAP C?
U 1 1 551C51C6
P 11550 6250
F 0 "C?" H 11550 6350 40  0000 L CNN
F 1 "1uF" H 11556 6165 40  0000 L CNN
F 2 "~" H 11588 6100 30  0000 C CNN
F 3 "~" H 11550 6250 60  0000 C CNN
	1    11550 6250
	1    0    0    -1  
$EndComp
$Comp
L CAP C?
U 1 1 551C51CC
P 11550 6750
F 0 "C?" H 11550 6850 40  0000 L CNN
F 1 "1uF" H 11556 6665 40  0000 L CNN
F 2 "~" H 11588 6600 30  0000 C CNN
F 3 "~" H 11550 6750 60  0000 C CNN
	1    11550 6750
	1    0    0    -1  
$EndComp
$Comp
L CAP C?
U 1 1 551C51D2
P 13350 6750
F 0 "C?" H 13350 6850 40  0000 L CNN
F 1 "1uF" H 13356 6665 40  0000 L CNN
F 2 "~" H 13388 6600 30  0000 C CNN
F 3 "~" H 13350 6750 60  0000 C CNN
	1    13350 6750
	1    0    0    -1  
$EndComp
$Comp
L CAP C?
U 1 1 551C51D8
P 13350 6250
F 0 "C?" H 13350 6350 40  0000 L CNN
F 1 "1uF" H 13356 6165 40  0000 L CNN
F 2 "~" H 13388 6100 30  0000 C CNN
F 3 "~" H 13350 6250 60  0000 C CNN
	1    13350 6250
	-1   0    0    1   
$EndComp
Text Notes 14650 6700 3    60   ~ 0
Direct connection to USB->RS232 cable.\n
Text Notes 15000 6850 0    79   ~ 0
1    DCD\n__________\n2     RD\n__________\n3     TD\n__________\n4    DTR\n__________\n5    GND\n__________\n6    DSR\n__________\n7    RTS\n__________\n8    CTS\n__________\n9     RI\n
NoConn ~ 11650 8100
NoConn ~ 13250 7350
Wire Wire Line
	11550 6050 11650 6050
Wire Wire Line
	11650 6450 11550 6450
Wire Wire Line
	11550 6550 11650 6550
Wire Wire Line
	11650 6950 11550 6950
Wire Wire Line
	13250 6550 13600 6550
Wire Wire Line
	13350 6950 13250 6950
Wire Wire Line
	13250 6450 13350 6450
Wire Wire Line
	13250 6050 13550 6050
Wire Wire Line
	13550 6050 13550 5900
Connection ~ 13350 6050
Wire Wire Line
	13600 6550 13600 6650
Connection ~ 13350 6550
Wire Wire Line
	13950 7400 13850 7400
Wire Wire Line
	13850 7400 13850 7250
Wire Wire Line
	13850 7250 14050 7250
Wire Wire Line
	11650 7450 11550 7450
Connection ~ 11550 7450
Wire Wire Line
	11550 7550 11650 7550
Connection ~ 11550 7550
Wire Wire Line
	11550 7650 11650 7650
Connection ~ 11550 7650
Wire Wire Line
	11550 7350 11550 7750
Wire Wire Line
	13250 8200 13300 8200
Wire Wire Line
	13300 8100 13300 8300
Wire Wire Line
	13950 7800 13450 7800
Wire Wire Line
	13450 7800 13450 8000
Wire Wire Line
	13450 8000 13250 8000
Wire Wire Line
	13950 8000 13700 8000
Wire Wire Line
	13700 8000 13700 7250
Wire Wire Line
	13700 7250 13250 7250
Wire Notes Line
	15000 6700 15000 8800
Wire Notes Line
	15600 8800 15600 6700
Wire Notes Line
	15600 6700 15000 6700
Wire Notes Line
	15000 8800 15600 8800
Wire Notes Line
	15250 6700 15250 8800
Wire Wire Line
	11650 7350 11550 7350
Wire Wire Line
	13250 8100 13300 8100
Connection ~ 13300 8200
Text Notes 14750 6950 3    60   ~ 0
I do not have a NULL MODEM cable.\n
Text Notes 14850 7000 3    60   ~ 0
If you do then swap pins 2 and 3 \n
Text Notes 14950 6700 3    60   ~ 0
going to the serial connector accordingly.\n
Wire Wire Line
	11450 8000 11650 8000
$Comp
L VCC #PWR?
U 1 1 551C59A4
P 11250 5600
F 0 "#PWR?" H 11250 5700 30  0001 C CNN
F 1 "VCC" H 11250 5700 30  0000 C CNN
F 2 "" H 11250 5600 60  0000 C CNN
F 3 "" H 11250 5600 60  0000 C CNN
	1    11250 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	11150 5750 11250 5750
Wire Wire Line
	11250 5600 11250 6050
Wire Wire Line
	11250 5850 11150 5850
Connection ~ 11250 5750
Wire Wire Line
	11250 5950 11150 5950
Connection ~ 11250 5850
Wire Wire Line
	11250 6050 11150 6050
Connection ~ 11250 5950
Entry Wire Line
	6000 6400 6100 6300
Wire Bus Line
	6100 2950 6100 6300
NoConn ~ 5550 6500
NoConn ~ 5550 6600
NoConn ~ 5550 6700
NoConn ~ 5550 6800
NoConn ~ 5550 6900
$Comp
L GND #PWR?
U 1 1 551C6734
P 6600 6900
F 0 "#PWR?" H 6600 6900 30  0001 C CNN
F 1 "GND" H 6600 6830 30  0001 C CNN
F 2 "" H 6600 6900 60  0000 C CNN
F 3 "" H 6600 6900 60  0000 C CNN
	1    6600 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 6500 6600 6500
Wire Wire Line
	6600 6500 6600 6900
Wire Wire Line
	6700 6600 6600 6600
Connection ~ 6600 6600
Wire Wire Line
	6700 6700 6600 6700
Connection ~ 6600 6700
Wire Wire Line
	6700 6800 6600 6800
Connection ~ 6600 6800
$Comp
L GND #PWR?
U 1 1 551C6A82
P 6600 4350
F 0 "#PWR?" H 6600 4350 30  0001 C CNN
F 1 "GND" H 6600 4280 30  0001 C CNN
F 2 "" H 6600 4350 60  0000 C CNN
F 3 "" H 6600 4350 60  0000 C CNN
	1    6600 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 3950 6600 3950
Wire Wire Line
	6600 3950 6600 4350
Wire Wire Line
	6700 4050 6600 4050
Connection ~ 6600 4050
Wire Wire Line
	6700 4150 6600 4150
Connection ~ 6600 4150
Wire Wire Line
	6700 4250 6600 4250
Connection ~ 6600 4250
$Comp
L VCC #PWR?
U 1 1 551C769F
P 1800 4600
F 0 "#PWR?" H 1800 4700 30  0001 C CNN
F 1 "VCC" H 1800 4700 30  0000 C CNN
F 2 "" H 1800 4600 60  0000 C CNN
F 3 "" H 1800 4600 60  0000 C CNN
	1    1800 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 4700 1800 4700
Wire Wire Line
	1800 4700 1800 4600
NoConn ~ 9450 8200
$Comp
L VCC #PWR?
U 1 1 551C852E
P 3850 6950
F 0 "#PWR?" H 3850 7050 30  0001 C CNN
F 1 "VCC" H 3850 7050 30  0000 C CNN
F 2 "" H 3850 6950 60  0000 C CNN
F 3 "" H 3850 6950 60  0000 C CNN
	1    3850 6950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 7000 3850 7000
Wire Wire Line
	3850 7000 3850 6950
$Comp
L XTAL4PIN X?
U 1 1 551C8CD1
P 4850 8450
F 0 "X?" H 4610 8810 60  0000 C CNN
F 1 "XTAL4PIN" H 4900 8150 60  0000 C CNN
F 2 "~" H 4850 8450 60  0000 C CNN
F 3 "~" H 4850 8450 60  0000 C CNN
F 4 "6.3360MHz" H 5000 8800 60  0000 C CNN "Freqency"
	1    4850 8450
	-1   0    0    1   
$EndComp
$Comp
L VCC #PWR?
U 1 1 551C8CD7
P 5450 8750
F 0 "#PWR?" H 5450 8850 30  0001 C CNN
F 1 "VCC" H 5450 8850 30  0000 C CNN
F 2 "" H 5450 8750 60  0000 C CNN
F 3 "" H 5450 8750 60  0000 C CNN
	1    5450 8750
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 551C8CDD
P 5450 8050
F 0 "#PWR?" H 5450 8050 30  0001 C CNN
F 1 "GND" H 5450 7980 30  0001 C CNN
F 2 "" H 5450 8050 60  0000 C CNN
F 3 "" H 5450 8050 60  0000 C CNN
	1    5450 8050
	-1   0    0    1   
$EndComp
NoConn ~ 4150 8650
Wire Wire Line
	5450 8250 5450 8050
Wire Wire Line
	5450 8750 5450 8650
Wire Wire Line
	3800 8350 4150 8350
$Comp
L XTAL4PIN X?
U 1 1 55209E51
P 10200 9300
F 0 "X?" H 9960 9660 60  0000 C CNN
F 1 "XTAL4PIN" H 10250 9000 60  0000 C CNN
F 2 "~" H 10200 9300 60  0000 C CNN
F 3 "~" H 10200 9300 60  0000 C CNN
F 4 "1.8432MHz" H 10350 9650 60  0000 C CNN "Freqency"
	1    10200 9300
	-1   0    0    1   
$EndComp
$Comp
L VCC #PWR?
U 1 1 55209E57
P 10800 9600
F 0 "#PWR?" H 10800 9700 30  0001 C CNN
F 1 "VCC" H 10800 9700 30  0000 C CNN
F 2 "" H 10800 9600 60  0000 C CNN
F 3 "" H 10800 9600 60  0000 C CNN
	1    10800 9600
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 55209E5D
P 10800 8900
F 0 "#PWR?" H 10800 8900 30  0001 C CNN
F 1 "GND" H 10800 8830 30  0001 C CNN
F 2 "" H 10800 8900 60  0000 C CNN
F 3 "" H 10800 8900 60  0000 C CNN
	1    10800 8900
	-1   0    0    1   
$EndComp
NoConn ~ 9500 9500
Wire Wire Line
	10800 9100 10800 8900
Wire Wire Line
	10800 9600 10800 9500
Wire Wire Line
	9150 9200 9500 9200
Wire Wire Line
	9450 7200 9150 7200
Wire Wire Line
	9150 7200 9150 9200
Text Label 9200 7200 0    60   ~ 0
UCLK
Wire Wire Line
	1550 4800 1850 4800
Wire Wire Line
	1850 4900 1750 4900
Wire Wire Line
	1750 4900 1750 4800
Connection ~ 1750 4800
$EndSCHEMATC
