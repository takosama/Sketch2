#include "ColorSensor.h"



ColorSensor::ColorSensor()
{
}


ColorSensor::~ColorSensor()
{
}

void ColorSensor::Read()
{
	int R = 0;
	for (int i = 0; i < 12; i++)
	{
		digitalWrite(this->CK, HIGH);
		delayMicroseconds(1);



		digitalWrite(this->CK, LOW);

		R << 1 + digitalRead(this->Dout);
		delayMicroseconds(1);

	}
	this->R = R / 16;
	
	int G = 0;
	for (int i = 0; i < 12; i++)
	{
		digitalWrite(this->CK, HIGH);
		delayMicroseconds(1);



		digitalWrite(this->CK, LOW);

		G << 1 + digitalRead(this->Dout);
		delayMicroseconds(1);
	}
	this->G = G / 16;

	int B = 0;
	for (int i = 0; i < 12; i++)
	{
		digitalWrite(this->CK, HIGH);
		delayMicroseconds(1);



		digitalWrite(this->CK, LOW);

		B << 1 + digitalRead(this->Dout);
		delayMicroseconds(1);
	}
	this->B = B / 16;

}

void ColorSensor::Init(uint16_t Dout)
{
	this->Dout = Dout;
	pinMode(Dout, INPUT);
}


