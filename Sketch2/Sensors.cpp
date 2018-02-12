#include "Sensors.h"
#include<Arduino.h>


void Sensors::ReadR()
{
	int tmp[4];
	tmp[0] = 0;
	tmp[1] = 0;
	tmp[2] = 0;
	tmp[3] = 0;
	delayMicroseconds(5);
	int k = 1;// 4096 / 2;
	for (int i = 0; i < 12; i++)
	{
		digitalWrite(this->_Clock, HIGH);
		delayMicroseconds(100);

		tmp[0] = tmp[0]  +k* digitalRead(this->_Out1);
		tmp[1] = tmp[1]  +k* digitalRead(this->_Out2);
		tmp[2] = tmp[2]  +k* digitalRead(this->_Out3);
		tmp[3] = tmp[3]  +k* digitalRead(this->_Out4);
		digitalWrite(this->_Clock, LOW);
		delayMicroseconds(100);
		k *= 2;
	}
	delayMicroseconds(5);
	this->R[0] = 0.8* this->R[0] + 0.2*(tmp[0] *0.5);
	this->R[1] = 0.8* this->R[1] + 0.2* tmp[1] *0.5;
	this->R[2] = 0.8* this->R[2] + 0.2* tmp[2] *0.5;
	this->R[3] = 0.8* this->R[3]+0.2* tmp[3]  * 0.5;
}

void Sensors::ReadG()
{
	int tmp[4];
	tmp[0] = 0;
	tmp[1] = 0;
	tmp[2] = 0;
	tmp[3] = 0;
	delayMicroseconds(5);
	int k = 1;// 4096 / 2;
	for (int i = 0; i < 12; i++)
	{
		digitalWrite(this->_Clock, HIGH);
		delayMicroseconds(100);

		tmp[0] = tmp[0] + k * digitalRead(this->_Out1);
		tmp[1] = tmp[1] + k * digitalRead(this->_Out2);
		tmp[2] = tmp[2] + k * digitalRead(this->_Out3);
		tmp[3] = tmp[3] + k * digitalRead(this->_Out4);
		digitalWrite(this->_Clock, LOW);
		delayMicroseconds(100);
		k *= 2;
	}
	delayMicroseconds(5);
	this->G[0] = this->G[0] * 0.8 + 0.2* tmp[0] * 0.5;
	this->G[1] = this->G[1] * 0.8 + 0.2*tmp[1] * 0.5;
	this->G[2] = this->G[2] * 0.8 + 0.2*tmp[2] * 0.5;
	this->G[3] = this->G[3] * 0.8 + 0.2*tmp[3] * 0.5;

}

void Sensors::ReadB()
{
	int tmp[4];
	tmp[0] = 0;
	tmp[1] = 0;
	tmp[2] = 0;
	tmp[3] = 0;
	delayMicroseconds(5);
	int k = 1;// 4096 / 2;
	for (int i = 0; i < 12; i++)
	{
		digitalWrite(this->_Clock, HIGH);
		delayMicroseconds(100);

		tmp[0] = tmp[0] + k * digitalRead(this->_Out1);
		tmp[1] = tmp[1] + k * digitalRead(this->_Out2);
		tmp[2] = tmp[2] + k * digitalRead(this->_Out3);
		tmp[3] = tmp[3] + k * digitalRead(this->_Out4);
		digitalWrite(this->_Clock, LOW);
		delayMicroseconds(100);
		k *= 2;
	}
	delayMicroseconds(5);

	this->B[0] = this->B[0] * 0.8 + 0.2* tmp[0] * 0.5;
	this->B[1] = this->B[1] * 0.8 + 0.2* tmp[1] * 0.5;
	this->B[2] = this->B[2] * 0.8 + 0.2* tmp[2] * 0.5;
	this->B[3] = this->B[3] * 0.8 + 0.2* tmp[3] * 0.5;

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
	this->_Out1 = Out1;
	this->_Out2 = Out2;
	this->_Out3 = Out3;
	this->_Out4 = Out4;
	pinMode(Gate, OUTPUT);
	pinMode(Clock, OUTPUT);
	pinMode(Range, OUTPUT);
	digitalWrite(Range, HIGH);
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
	delayMicroseconds(5);
	ReadR();
	ReadG();
	ReadB();
	digitalWrite(this->_Clock, HIGH);
	delayMicroseconds(1);

	digitalWrite(this->_Clock, LOW);
	delayMicroseconds(1);
	digitalWrite(this->_Clock, HIGH);
	delayMicroseconds(1);

	digitalWrite(this->_Clock, LOW);
	delayMicroseconds(1);
	digitalWrite(this->_Clock, HIGH);
	delayMicroseconds(1);

	digitalWrite(this->_Clock, LOW);
	delayMicroseconds(1);
	digitalWrite(this->_Clock, HIGH);
	delayMicroseconds(1);

	digitalWrite(this->_Clock, LOW);
	delayMicroseconds(1);
	digitalWrite(this->_Clock, HIGH);
	delayMicroseconds(1);

	digitalWrite(this->_Clock, LOW);
	delayMicroseconds(1);
	digitalWrite(this->_Clock, HIGH);
	delayMicroseconds(1);

	digitalWrite(this->_Clock, LOW);
	delayMicroseconds(1);
	digitalWrite(this->_Clock, HIGH);
	delayMicroseconds(1);

	digitalWrite(this->_Clock, LOW);
	delayMicroseconds(1);
	digitalWrite(this->_Clock, HIGH);
	delayMicroseconds(1);

	digitalWrite(this->_Clock, LOW);
	delayMicroseconds(1);
	digitalWrite(this->_Clock, HIGH);
	delayMicroseconds(1);

	digitalWrite(this->_Clock, LOW);
	delayMicroseconds(1);
	digitalWrite(this->_Clock, HIGH);
	delayMicroseconds(1);

	digitalWrite(this->_Clock, LOW);
	delayMicroseconds(1);
	digitalWrite(this->_Clock, HIGH);
	delayMicroseconds(1);

	digitalWrite(this->_Clock, LOW);
	delayMicroseconds(1);

}
