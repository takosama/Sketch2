#pragma once
#include"Moter.h"
class Omuni
{
	Moter _l;
	Moter _r;
	Moter _t;
public:
	Omuni();
	~Omuni();
	void Init(Moter l, Moter r, Moter t);
	void Set(int angle,int dif);
};

