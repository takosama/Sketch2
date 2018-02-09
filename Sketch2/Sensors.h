#pragma once
#include<Arduino.h>
class Sensors
{
	uint16_t _Gate;
	uint16_t _Clock;
	uint16_t _Range;
	uint16_t _Out1;
	uint16_t _Out2;
	uint16_t _Out3;
	uint16_t _Out4;
	void ReadR();
	void ReadG();
	void ReadB();
public:
	byte R[4];
	byte G[4];
	byte B[4];

	Sensors();
	~Sensors();
	void Init(uint16_t Gate, uint16_t Clock, uint16_t Range, uint16_t Out1, uint16_t Out2, uint16_t Out3, uint16_t Out4);
	void Read();
};

