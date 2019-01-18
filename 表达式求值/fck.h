#pragma once
#include <string>
#include <stack>
#include <iostream>
using namespace std;
class expression
{
	stack<string> sign(50);
	stack<double> num(50);
	expression(string& str) {
		sign.append("#");
	}
	void calculate(string str)
private:
	string z;//运算符
	double x;//第一个操作数
	double y;//第二个操作数
	double _value;
	void 入栈_sign;
	void 入栈_num;
	bool _operator_checked();
	int _cost_value;
	int _get_cost(string k);
	void _cal_steps(int &a);
	void _single_cal(double x, string z, double y);
	void _enter_stack_num();
	void _enter_stack_sign();
};

void expression::calculate(string str)
{
	for (int i = 0; i < str.length(); i++) {
		//获取一个string
		string c = substr(i, 1);
		while (c != "#" || sign.GetTop() != "#") {
			if (_operator_checked)//第一个字符是操作符
				_enter_stack_sign(c);
			else if 第一个字符是数字
				_enter_stack_num(c)；
			else return；//报错，输入非公式错误信息
		}
		
	}
	输出最终值
}

//入栈函数
bool expression::_enter_stack_sign(string c) {
	int a;
	a = _get_cost(c);
	_cal_steps(a);
	return1
};

//对比权值决定直接入栈还是计算再入栈
void expression::_cal_steps(int &a) {
	if (a > _cost_value)
	{//入栈 _sign;
		_cost_value = a;
		
	}
	else if (sign.top() == '#') {
		return true;
	}
	else
	{//不入栈，num出栈2值，计算并传入私有函数_value;重新入栈；sign出栈一位符号
		sign.pop(z);//运算符
		num.pop(y);//第二个操作数
		num.pop(x);//第一个操作数
		_single_cal(x, z, y);//计算并传入栈顶num
		_cost_value = _get_cost(sign.top());//cost_value等于sign栈顶的值;
	    _cal_steps(a);//再比较，直至写入或者
	};
};

计算栈顶值，传入num栈顶
void expression::_single_cal(double x,char z,double y)
{
	switch (z)
	{
	case '+':
		_value = x + y;
	case '*':
		_value = x * y;
	case '/':
		_value = x / y;
	case '-':
		_value = x - y;
	default:
		break;
	}
	//num入栈函数
	num.push(_value)
}

void expression::_entered_stack_num(char d)
	{
	num.push(d);
	}




	//检测字符是否是运算符
	bool expression::operator_checked(char c){
	switch (c) {
	case '#':
		return true;
	case '+':
		return true;
	case '-':
		return true;
	case '*' :
		return true;
	case '/':
		return true;
	case '(':
		return true;
	case ')' :
		return true;
	case '=' :
		return true;
	default case:
		cout << "输入错误,不是运算符" << endl;
		return false;
	};
	//判断运算符优先级
	Judge(sign.top(),c ){

		if (sign.top() == c)
			return '=';
		else if((c=="*"||c=="/")&&(sign.top()=="+"|| sign.top() == "-" || sign.top() == "#" sign.top() == "="|| ))
			return '>'
	};
}

//获取栈顶的权值
	int expression::_get_cost(string a1) {
	int a1;
	switch (c) {
	case '#':
		a1 = 1;
		return a1;
	case:'+' :
		a1 = 3
		return a1;
	case:'-' :
		a1 = 3
		return a1;
	case:'*' :
		a1 = 5;
		return a1;
	case:'/' :
		a1 = 5;
		return a1;
	case:'(' :
		a1 = 2;
		return a1;
	case:')' :
		a1 = 7;
		return a1;
	case:'=' :
		a1 = 2;
		return a1;
	default case:
		cout << "输入错误" << endl;
		return 0
	};
};

