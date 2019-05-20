#pragma once
#ifndef __CD_H__
#define __CD_H__

class Cd
{
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
public:
	Cd(const char *s1, const char* s2, int n, double x);
	Cd(const Cd & d);
	Cd();
	virtual ~Cd();
	virtual void Report() const;
	virtual Cd &operator=(const Cd & d);
};

#endif // !__CD_H__

