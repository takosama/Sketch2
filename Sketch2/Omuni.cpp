#include "Omuni.h"



Omuni::Omuni()
{
}


Omuni::~Omuni()
{
}

void Omuni::Init(Moter l, Moter r, Moter t)
{
	this->_l = l;
	this->_r = r;
	this->_t = t;
}



// -1~1 
void Omuni::Set(int angle,int dif)
{
	if (angle > 1) angle = 1;
	if (angle < -1)angle = -1;

	angle *= 256;
	angle -= 128;
	int ls = 128 + angle;
	int rs = 128 - angle;
	this->_l.SetSpeed(ls);
	this->_r.SetSpeed(rs);
	this->_t.SetSpeed(dif);
}

void Omuni::Max()
{
	
	this->_l.SetSpeed(-128);
	this->_r.SetSpeed(-128);
	//this->_t.SetSpeed(128);
}
