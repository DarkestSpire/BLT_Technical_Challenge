/* Brady Heater
 * April 20 2023
 * BLT Technical Challenge
*/

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

// Timer Value
#define timerSpeed16Bit 	10000 //Hz

// Encoder Values
unsigned short int currentEncoderValue = 0;
unsigned short int preveousEncoderValue = 0;
unsigned short int encoderPin = 0;

// Define LED output
#define LED_AT_65000 		21 // Toggle this at 65000 from the encoder
#define LED_3s_5BLINK 		22 // At 3 seconds blink 5 times

// LED Timer
unsigned int LEDtime = 0;


// Toggle LED_AT_65000
void toggleLED_AT_65000() {
	if (digitalRead (LED_AT_65000) == 0) {
		digitalWrite (LED_AT_65000, HIGH);
	}
	else {
		digitalWrite (LED_AT_65000, LOW);
	} 
}

// Blink LED_3s_5BLINK 5 Times
void checkLED_3s_5BLINK() {
	// find 3s
	if (LEDtime >= timerSpeed16Bit * 3) {
		for (int i=0; i<5; i++){
			digitalWrite (LED_3s_5BLINK, HIGH);
			delay(50);
			digitalWrite (LED_3s_5BLINK, LOW);
			delay(50);
		}
		LEDtime = 0;
	}
	digitalWrite (LED_3s_5BLINK, LOW);
}

// After increace read encoder
void readEncoder() {
	int mask;
	for (int i=0; i<16; i++) {
		encoderPin = digitalRead(i);

		mask = 1 << i;
		currentEncoderValue = ((currentEncoderValue & ~mask) | (encoderPin << i));
	}

	// This allows to tract overflow flags and LED on/off count offset
	LEDtime += abs(currentEncoderValue-preveousEncoderValue);

	// Toggle LED
	if (preveousEncoderValue <= 65000 & currentEncoderValue > 65000) {
		toggleLED_AT_65000();
	}

	preveousEncoderValue = currentEncoderValue;
	//printf("Encoder: %d, LED_CountDown: %d, Rollover: %d\n", currentEncoderValue, LED_Countdown, rollover);
}

int main(void) {
	printf("Reading Encoder at %d Hz\n", timerSpeed16Bit);
	printf("Press 'CTRL-C' to stop\n");

	wiringPiSetup();

	// Inialize the LED pins
	pinMode (LED_AT_65000, OUTPUT);
	pinMode (LED_3s_5BLINK, OUTPUT);
	digitalWrite (LED_AT_65000, HIGH);
	digitalWrite (LED_3s_5BLINK, HIGH);

	// initalize encoder read values
	for (int i=0; i<16; i++) {
		pinMode (i, INPUT);
		pullUpDnControl (i, PUD_UP) ;
	}

	// Initalize ISR for encoder
	wiringPiISR(0, INT_EDGE_BOTH, &readEncoder);

	//Main Loop
	while(1) {
		checkLED_3s_5BLINK();
	}

	return 0;
}

// g++ Encoder_Capture.c -o encoder -lwiringPi
// ./encoder


