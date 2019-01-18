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
	char z;//�����
	double x;//��һ��������
	double y;//�ڶ���������
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
	//��ȡһ��string		//const char* c = str.substr(i, 1).data();
	int i = 0;
	char d = str[0];
		while (i < str.length()) {
			
			char d = str[i];
			if (_operator_checked(d))//��һ���ַ��ǲ�����
			{
				_enter_stack_sign(d);
			}
			else  //��һ���ַ�������
			{
				cout << "��" << i << "��������" << endl;
				_enter_stack_num(d);
			};
			i++;
		};
		cout << _value<<num.top() << endl;
	//};
	//�������ֵ
};

//��ջ����sign
void expression::_enter_stack_sign(char d) {
	int a;
	a = _get_cost(d);
	cout << "����Ȩֵ is " << a << endl;
	_cal_steps(a,d);
	//return 1;
};

//�Ա�Ȩֵ����ֱ����ջ���Ǽ�������ջ
void expression::_cal_steps(int &a,char d) {
	if (a > _cost_value)
	{//��ջ _sign;
		sign.push(d);
		cout << "��ջ������" << d << endl;
		_cost_value = a;
		
	}
	else 
		if(!(sign.top()=='='))
	{//����ջ��num��ջ2ֵ�����㲢����˽�к���_value;������ջ��sign��ջһλ����

		z=sign.top();//�����
		sign.pop();
        y = num.top();
		//cout << "x is" << x << endl;
		num.pop();//�ڶ���������
		x = num.top(); 
		num.pop();//��һ��������
		cout << "numջ��һλ is" << y << endl;
		cout << "numջ�ڶ�λ is" << x << endl;
		cout << "�������� is " << z << endl; 
		_single_cal(x, z, y);//���㲢����ջ��num
		_cost_value = _get_cost(sign.top());	//cost_value����signջ����ֵ;
	   _cal_steps(a,d);//�ٱȽϣ�ֱ��д�����
	}
	     else sign.pop();//�Ⱥų�ջ
	cout << "signջ���һλ�� " << sign.top() << endl;
};

//����ջ��ֵ������numջ��
void expression::_single_cal(double x,char z,double y)
{
	switch (z)
	{
	case '+':
		_value = x + y;
		cout << "ִ��+����"<<endl;
		break;
	case '*':
		_value = x * y;
		cout << "ִ��*s����" << endl;
		break;
	case '/':
		_value = x / y;
		break;
	case '-':
		_value = x - y;
		break;
	case '#':
		cout << "�����治Ҫ��#" << endl;
		break;
	default:
		cout << "�ⲽ����ִ����û�а���" << endl;
		break;
	};
	//num��ջ����
	num.push(_value);
	cout << "value is" << _value;
};

void expression::_enter_stack_num(char d)
	{
	char *p= &d;
	double e = atof(p);
	cout << "num"<<e<<"��ջ�ɹ�" << endl;
	num.push(e);
};




	//����ַ��Ƿ��������
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
		cout << "�������,���������" << endl;
		return false;
		break;
	}
};
	
	
	
////�ж���������ȼ�
//	Judge(sign.top(),char c ){
//
//		if (sign.top() == c)
//			return '=';
//		else if ((c == "*" || c == "/") && (sign.top() == "+" || sign.top() == "-" || sign.top() == "#" sign.top() == "=" || ))
//			return '>';
//	};
//}

//��ȡջ����Ȩֵ
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
		a1 = 2;//�Ⱥ�ֵ�ȣ�С
		return a1;
	default :
		cout << "�������" << endl;
		return 0;
	};
};

