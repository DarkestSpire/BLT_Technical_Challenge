
encoder: Encoder_Capture.o
	g++ Encoder_Capture.o -o encoder -lwiringPi

Encoder_Capture.o: Encoder_Capture.c
	g++ -c Encoder_Capture.c

clean:
	rm *.o encoder
	