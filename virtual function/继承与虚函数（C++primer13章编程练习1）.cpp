// 继承与虚函数（C++primer13章编程练习1）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "Classic1.h"
using namespace std;

void Bravo(const Cd &disk);
int main()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic1 c2 = Classic1("Piano Sonata in B flat, Fantasia in C", "Alfred Bredel", "Philips", 2, 57.17);
	Cd *pcd = &c1;


	cout << "using object directly:\n";
	c1.Report();
	c2.Report();
	cout << "\n";
	cout << "using type cd* pointer to object:\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();
	cout << "\n";
	cout << " calling a function with a cd reference argument: \n";
	Bravo(c1);
	Bravo(c2);
	cout << "\n";
	cout << "tesing assignment: \n";
	Classic1 copy;
	copy = c2;
	copy.Report();
	
	//char a[50];
	//const char *p = "hello";
	//strcpy_s(a,strlen(p)+1,p);//赋值字符串于数组
	//cout << a;
	return 1;
//    std::cout << "Hello World!\n"; 
}
void Bravo(const Cd &disk)
{
	disk.Report();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
