# BLT_Technical_Challenge

1. You will need to connect the 16 Bit timer and LED to pins on the Pi 3B located bellow
	Pi	|	Conn			Pi	|	Conn
	1	|	N/A 			2	|	N/A
	3	|	16T 8			4	|	N/A
	5	|	16BT 9			6	|	N/A
	7	|	16BT 7			8	|	16BT 15
	9	|	N/A	    		10	|	N/A
	11	|	16BT 0			12	|	16BT 1
	13	|	16BT 2			14	|	N/A
	15	|	16BT 3			16	|	16BT 4
	17	|	N/A		    	18	|	16BT 5
	19	|	16BT 12			20	|	N/A
	21	|	16BT 13			22	|	16BT 6
	23	|	16BT 14			24	|	16BT 10
	25	|	N/A 			26	|	16BT 11
	27	|	N/A 			28	|	N/A
	29	|	LED 1*			30	|	N/A
	31	|	LED 2*			32	|	N/A
	33	|	N/A 			34	|	N/A
	35	|	N/A 			36	|	N/A
	37	|	N/A 			38	|	N/A
	39	|	N/A 			40	|	N/A
	*LED 1 - LED will toggle at timer value 65000 (Blue)
	*LED 2 - LED will blink 5 times every 3 seconds (Green)

2. Open terminal to this folder and type 'make' to build

3. type './encoder' next. program will begin polling for encoder.

4. Press 'CTRL-C' to end program

5. By default 16Bit timer frequency is 10000Hz this can be changed in  Encoder_Capture.c
	At line 11 change the timerSpeed16Bit to another value, and repeat steps 2 though 4
