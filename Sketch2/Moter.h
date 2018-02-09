#pragma once
#include<Arduino.h>
class Moter
{
	uint16_t _PWM;
	uint16_t _DIR;
	uint16_t _OD;
public:
	Moter();
	~Moter();
	void Init(uint16_t PWM, uint16_t DIR, uint16_t OD);
	void SetSpeed(int speed);
};

