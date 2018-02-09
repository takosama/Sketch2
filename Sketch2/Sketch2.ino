/*
i Created:	2018/02/09 19:15:03
 Author:	takos
*/
#include"Omuni.h"
#include<Arduino.h>
#include"Sensors.h"
Omuni omuni;
Sensors sensors;
const uint16_t input0;
const uint16_t input1;
const uint16_t input2;
// the setup function runs once when you press reset or power the board
const uint16_t  LeanPin = 0;
bool  isLean = false;
void setup() {
	delay(1000);
	TCCR3B = (TCCR3B & 0b11111000) | 0x01;
	TCCR4B = (TCCR4B & 0b11111000) | 0x01;
	pinMode(LeanPin, INPUT_PULLUP);
	pinMode(input0, INPUT_PULLUP);
	pinMode(input1, INPUT_PULLUP);
	pinMode(input2, INPUT_PULLUP);
	delay(100);

	if (digitalRead(LeanPin) == 0)  isLean = true;
	if (isLean)
	{
		Serial.begin(115200);
	}
	sensors.Init(A0, A1, A2, A3, A4, A5, A6);
	Moter m0;
	Moter m1;
	Moter m2;
	m0.Init(2, 3, 4);
	m1.Init(5,6, 7);
	m2.Init(8, 9, 10);
	omuni.Init(m0, m1, m2);
	
}
int cnt = 0;
// the loop function runs over and over again until power down or reset
void loop() {
	for (int i = 0; i < 4; i++)
		sensors.Read();

	int frontR = sensors.R[0] - sensors.R[1];
	int backR = sensors.R[2] - sensors.R[3];

	int frontG = sensors.G[0] - sensors.G[1];
	int backG = sensors.G[2] - sensors.G[3];

	int frontB = sensors.B[0] - sensors.B[1];
	int backB = sensors.B[2] - sensors.B[3];

	//if (isLean)
	//{
	//	Serial.print(frontR);
	//	Serial.print(",");
	//	Serial.print(frontG);
	//	Serial.print(",");
	//	Serial.print(frontB);
	//	Serial.print(",");
	//	Serial.print(backR);
	//	Serial.print(",");
	//	Serial.print(backG);
	//	Serial.print(",");
	//	Serial.print(backB);
	//	Serial.print(",");
	//}


	//read 10ms
	delay(90);
	//total 100
	int i0 = digitalRead(input0);
	int i1 = digitalRead(input1);
	int i2 = digitalRead(input2);

	int front = frontR + frontG + frontB;
	int back = backR + backG + backB;

	int angle = (front - back)*0.01;
	int div = (front + back)*0.01;
	omuni.Set(angle, div);


	if (isLean)
	{
		Serial.print(angle);
		Serial.print(",");
		Serial.print(div);
		Serial.print(",");

		Serial.print(i0);
		Serial.print(",");
		Serial.print(i1);
		Serial.print(",");
		Serial.println(i2);
	}
}


