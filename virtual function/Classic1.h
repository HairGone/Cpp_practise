#ifndef __CLASSIC1_H__
#define __CLASSIC1_H__
#include "Cd.h"
#include <iostream>
using namespace std;
class Classic1 :
	public Cd
{
private:
	char products[50];
public:
	Classic1(const char *s3, const char *s1, const char* s2, int n, double x);
	Classic1() {};
	~Classic1();
	virtual void Report() const;
	virtual Classic1& operator=(const Classic1 & another);
}; //Cd & Cd::operator=(const Cd & d)
#endif // !__CLASSIC1_H__

#pragma once



