#include "Sensors.h"
#include<Arduino.h>


void Sensors::ReadR()
{
	int tmp[4];
	delayMicroseconds(5);
	for (int i = 0; i < 12; i++)
	{
		digitalWrite(this->_Clock, HIGH);
		delayMicroseconds(1);

		digitalWrite(this->_Clock, LOW);
		tmp[0] = tmp[0] << 1 + digitalRead(this->_Out1);
		tmp[1] = tmp[1] << 1 + digitalRead(this->_Out2);
		tmp[2] = tmp[2] << 1 + digitalRead(this->_Out3);
		tmp[3]= tmp[3]<<1+		digitalRead(this->_Out4);
		delayMicroseconds(1);

	}
	delayMicroseconds(5);

	this->R[0] = tmp[0] / 16;
	this->R[1] = tmp[1] / 16;
	this->R[2] = tmp[2] / 16;
	this->R[3] = tmp[3] / 16;
}

void Sensors::ReadG()
{
	int tmp[4];
	delayMicroseconds(5);
	for (int i = 0; i < 12; i++)
	{
		digitalWrite(this->_Clock, HIGH);
		delayMicroseconds(1);

		digitalWrite(this->_Clock, LOW);
		tmp[0] = tmp[0] << 1 + digitalRead(this->_Out1);
		tmp[1] = tmp[1] << 1 + digitalRead(this->_Out2);
		tmp[2] = tmp[2] << 1 + digitalRead(this->_Out3);
		tmp[3] = tmp[3] << 1 + digitalRead(this->_Out4);
		delayMicroseconds(1);

	}
	delayMicroseconds(5);

	this->G[0] = tmp[0] / 16;
	this->G[1] = tmp[1] / 16;
	this->G[2] = tmp[2] / 16;
	this->G[3] = tmp[3] / 16;

}

void Sensors::ReadB()
{
	int tmp[4];
	delayMicroseconds(5);
	for (int i = 0; i < 12; i++)
	{
		digitalWrite(this->_Clock, HIGH);
		delayMicroseconds(1);

		digitalWrite(this->_Clock, LOW);
		tmp[0] = tmp[0] << 1 + digitalRead(this->_Out1);
		tmp[1] = tmp[1] << 1 + digitalRead(this->_Out2);
		tmp[2] = tmp[2] << 1 + digitalRead(this->_Out3);
		tmp[3] = tmp[3] << 1 + digitalRead(this->_Out4);
		delayMicroseconds(1);

	}
	delayMicroseconds(5);

	this->B[0] = tmp[0] / 16;
	this->B[1] = tmp[1] / 16;
	this->B[2] = tmp[2] / 16;
	this->B[3] = tmp[3] / 16;

}

Sensors::Sensors()
{
}


Sensors::~Sensors()
{
}

void Sensors::Init(uint16_t Gate, uint16_t Clock, uint16_t Range, uint16_t Out1, uint16_t Out2, uint16_t Out3, uint16_t Out4)
{
	this->_Gate = Gate;
	this->_Clock = Clock;
	this->_Range = Range;
	pinMode(Gate, OUTPUT);
	pinMode(Clock, OUTPUT);
	pinMode(Range, OUTPUT);
	pinMode(Out1, INPUT);
	pinMode(Out2, INPUT);
	pinMode(Out3, INPUT);
	pinMode(Out4, INPUT);
}



void Sensors::Read()
{
	digitalWrite(this->_Gate, HIGH);
	delay(10);
	digitalWrite(this->_Gate, LOW);
	delayMicroseconds(4);
	ReadR();
	ReadG();
	ReadB();
}
