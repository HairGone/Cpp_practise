#pragma once
#include <string>
#include <stack>
#include <iostream>
using namespace std;
class expression
{
public:
	int size = 50;
	stack<char> sign;
	stack<double> num;
	expression(string& str) {
		sign.push('#');
	//	str.append("#");
	};
	void calculate(string str);
private:
	char z;//运算符
	double x;//第一个操作数
	double y;//第二个操作数
	double _value;
	bool _operator_checked(char c);
	int _cost_value=1;
	int _get_cost(char k);
	void _cal_steps(int &a,char d);
	void _single_cal(double x, char z, double y);
	void _enter_stack_num(char d);
	void _enter_stack_sign(char d);
};

void expression::calculate(string str)
{
	//for (int i = 0; i < str.length(); i++) {
	//获取一个string		//const char* c = str.substr(i, 1).data();
	int i = 0;
	char d = str[0];
		while (i < str.length()) {
			
			char d = str[i];
			if (_operator_checked(d))//第一个字符是操作符
			{
				_enter_stack_sign(d);
			}
			else  //第一个字符是数字
			{
				cout << "第" << i << "个是数字" << endl;
				_enter_stack_num(d);
			};
			i++;
		};
		cout << _value<<num.top() << endl;
	//};
	//输出最终值
};

//入栈函数sign
void expression::_enter_stack_sign(char d) {
	int a;
	a = _get_cost(d);
	cout << "符号权值 is " << a << endl;
	_cal_steps(a,d);
	//return 1;
};

//对比权值决定直接入栈还是计算再入栈
void expression::_cal_steps(int &a,char d) {
	if (a > _cost_value)
	{//入栈 _sign;
		sign.push(d);
		cout << "入栈符号是" << d << endl;
		_cost_value = a;
		
	}
	else 
		if(!(sign.top()=='='))
	{//不入栈，num出栈2值，计算并传入私有函数_value;重新入栈；sign出栈一位符号

		z=sign.top();//运算符
		sign.pop();
        y = num.top();
		//cout << "x is" << x << endl;
		num.pop();//第二个操作数
		x = num.top(); 
		num.pop();//第一个操作数
		cout << "num栈第一位 is" << y << endl;
		cout << "num栈第二位 is" << x << endl;
		cout << "操作数是 is " << z << endl; 
		_single_cal(x, z, y);//计算并传入栈顶num
		_cost_value = _get_cost(sign.top());	//cost_value等于sign栈顶的值;
	   _cal_steps(a,d);//再比较，直至写入或者
	}
	     else sign.pop();//等号出栈
	cout << "sign栈最后一位是 " << sign.top() << endl;
};

//计算栈顶值，传入num栈顶
void expression::_single_cal(double x,char z,double y)
{
	switch (z)
	{
	case '+':
		_value = x + y;
		cout << "执行+操作"<<endl;
		break;
	case '*':
		_value = x * y;
		cout << "执行*s操作" << endl;
		break;
	case '/':
		_value = x / y;
		break;
	case '-':
		_value = x - y;
		break;
	case '#':
		cout << "最上面不要放#" << endl;
		break;
	default:
		cout << "这步到底执行了没有啊！" << endl;
		break;
	};
	//num入栈函数
	num.push(_value);
	cout << "value is" << _value;
};

void expression::_enter_stack_num(char d)
	{
	char *p= &d;
	double e = atof(p);
	cout << "num"<<e<<"入栈成功" << endl;
	num.push(e);
};




	//检测字符是否是运算符
bool expression::_operator_checked(char c) {
	switch (c) {
	case '#':
		return true;
		break;
	case '+':
		return true;
		break;
	case '-':
		return true;
		break;
	case '*':
		return true;
		break;
	case '/':
		return true;
		break;
	case '(':
		return true;
		break;
	case ')':
		return true;
		break;
	case '=':
		return true;
		break;
	default:
		cout << "输入错误,不是运算符" << endl;
		return false;
		break;
	}
};
	
	
	
////判断运算符优先级
//	Judge(sign.top(),char c ){
//
//		if (sign.top() == c)
//			return '=';
//		else if ((c == "*" || c == "/") && (sign.top() == "+" || sign.top() == "-" || sign.top() == "#" sign.top() == "=" || ))
//			return '>';
//	};
//}

//获取栈顶的权值
	int expression::_get_cost(char d) {
	int a1;
	switch (d) {
	case '#':
		a1 = 1;
		return a1;
	case '+' :
		a1 = 3;
		return a1;
	case '-' :
		a1 = 3;
		return a1;
	case '*' :
		a1 = 5;
		return a1;
	case '/' :
		a1 = 5;
		return a1;
	case '(' :
		a1 = 7;
		return a1;
	case ')' :
		a1 = 2;
		return a1;
	case '=' :
		a1 = 2;//等号值比）小
		return a1;
	default :
		cout << "输入错误" << endl;
		return 0;
	};
};

