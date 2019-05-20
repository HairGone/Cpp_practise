#include "pch.h"
#include "Cd.h"
#include<iostream>
using namespace std;

Cd::Cd()
{
}
Cd::Cd(const char *s1, const char* s2, int n, double x)
{
	strcpy_s(performers, strlen(s1)+1,s1);
	strcpy_s(label, strlen(s1) + 1, s2);

	selections = n;
	playtime = x;
}
Cd::Cd(const Cd & d)
{
	cout << "调用拷贝\n";
	//char(&pt1)[50] = performers;
	////pt1 = performers[50];
	//char (&pt2) [20] = label;
	//*pt1 = *(d.performers);
	//*pt2 = *(d.label);
	//selections = d.selections;
	//playtime = d.playtime;
}


Cd::~Cd()
{
}

void Cd::Report() const
{
	cout << "Cd Report() \n";
	cout << "performers: " << performers << endl;
	cout << "label: " << label << endl;
	cout << "selections: " << this->selections << endl;
	cout << "playtime: " << this->playtime << endl;
}

Cd & Cd::operator=(const Cd & d)
{
	cout << "基类赋值\n";
	strcpy_s(performers, strlen(d.performers) + 1, d.performers);
	strcpy_s(label, strlen(d.label) + 1, d.label);

	selections = d.selections;
	playtime = d.playtime;
	
	return *this;
}