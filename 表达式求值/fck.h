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
	string z;//�����
	double x;//��һ��������
	double y;//�ڶ���������
	double _value;
	void ��ջ_sign;
	void ��ջ_num;
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
		//��ȡһ��string
		string c = substr(i, 1);
		while (c != "#" || sign.GetTop() != "#") {
			if (_operator_checked)//��һ���ַ��ǲ�����
				_enter_stack_sign(c);
			else if ��һ���ַ�������
				_enter_stack_num(c)��
			else return��//��������ǹ�ʽ������Ϣ
		}
		
	}
	�������ֵ
}

//��ջ����
bool expression::_enter_stack_sign(string c) {
	int a;
	a = _get_cost(c);
	_cal_steps(a);
	return1
};

//�Ա�Ȩֵ����ֱ����ջ���Ǽ�������ջ
void expression::_cal_steps(int &a) {
	if (a > _cost_value)
	{//��ջ _sign;
		_cost_value = a;
		
	}
	else if (sign.top() == '#') {
		return true;
	}
	else
	{//����ջ��num��ջ2ֵ�����㲢����˽�к���_value;������ջ��sign��ջһλ����
		sign.pop(z);//�����
		num.pop(y);//�ڶ���������
		num.pop(x);//��һ��������
		_single_cal(x, z, y);//���㲢����ջ��num
		_cost_value = _get_cost(sign.top());//cost_value����signջ����ֵ;
	    _cal_steps(a);//�ٱȽϣ�ֱ��д�����
	};
};

����ջ��ֵ������numջ��
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
	//num��ջ����
	num.push(_value)
}

void expression::_entered_stack_num(char d)
	{
	num.push(d);
	}




	//����ַ��Ƿ��������
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
		cout << "�������,���������" << endl;
		return false;
	};
	//�ж���������ȼ�
	Judge(sign.top(),c ){

		if (sign.top() == c)
			return '=';
		else if((c=="*"||c=="/")&&(sign.top()=="+"|| sign.top() == "-" || sign.top() == "#" sign.top() == "="|| ))
			return '>'
	};
}

//��ȡջ����Ȩֵ
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
		cout << "�������" << endl;
		return 0
	};
};

