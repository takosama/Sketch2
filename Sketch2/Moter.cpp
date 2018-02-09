#include "Moter.h"
#include<Arduino.h>


Moter::Moter()
{
}


Moter::~Moter()
{

}

void Moter::Init(uint16_t PWM, uint16_t DIR, uint16_t OD)
{
	pinMode(PWM, OUTPUT);
	pinMode(DIR, OUTPUT);
	pinMode(OD, OUTPUT);

	digitalWrite(OD, HIGH);
}

void Moter::SetSpeed(int speed)
{
	int sp = 0;
	int dir = 0;
	if (speed > 255)
		speed = 255;
	if (speed < -255)
		speed = -255;
	if (speed != 0)
	{
		if (speed < 10 && speed>0)speed = 10;
		else if (speed > -10 && speed < 0) speed = -10;
	}

	if (speed > 0)
		dir = 0;
	if (speed < 0)
		dir = 1;
	sp = abs(speed);

	digitalWrite(this->_DIR, dir);
	analogWrite(this->_PWM, sp);

}
