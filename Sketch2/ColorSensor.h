#pragma once
class ColorSensor
{
uint16_t Dout = 0;

public:
	ColorSensor();
	~ColorSensor();
	void Read();
	void Init( uint16_t Dout);
	byte R = 0;
	byte G = 0;
	byte B = 0;
};

