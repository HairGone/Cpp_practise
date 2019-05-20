#include "pch.h"
#include "Classic1.h"


Classic1::Classic1(const char *s3, const char *s1, const char* s2, int n, double x):Cd(s1,s2,n,x)
{
	strcpy_s(products, strlen(s3) + 1, s3);
	
}

void Classic1::Report() const
{
	Cd::Report();
	cout << "products: " << this->products << endl;
}
Classic1::~Classic1()
{
}

Classic1 & Classic1::operator=(const Classic1 & another) {
	cout << "子类赋值构造函数\n";
	Cd::operator=(another);
	strcpy_s(products, strlen(another.products) + 1, another.products);
	return *this;
}