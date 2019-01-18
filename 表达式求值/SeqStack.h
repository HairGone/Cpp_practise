#pragma once
#include <exception>
#include <stack>

template<class T>
class SeqStack :public Stack<T>
{
public:
	SeqStack(int MaxStackSize = 10);
	~SeqStack() { if (stack) delete[] stack; };
	virtual bool IsEmpty() const { return top == 1; };
	virtual bool IsFull() const { return top == MaxSize - 1; };
	T & GetTop() const;
	virtual bool Push(const T&x);
	virtual bool Pop(T&x);
	virtual bool Pop();
	virtual void ClearStack{ top = -1; };
	virtual void Output(ostream& out) const;
private:
	int top;
	int MaxSize;
	T*stack;
};

template <class T>
SeqStack<T>::SeqStack(int MaxStackSize)
{
	MaxSize = MaxStackSize;
	stack = new T[MaxStackSize];
	if (stack = NULL) throw NoMem(); top = -1;
};


template<class T>
T& SeqStack<T>::GetTop() const
{
	if (IsEmpty()) throw OutOfBounds(); else return stack[top];
};

template<class T>
bool SeqStack<T>::Push(const T&x)
{
	if (IsFull()) throw OutOfBounds();
	stack[++top] = x;
	return true;
};

template<class T>
bool SeqStack<T>::Pop(T&x)
{
	if (IsEmpty()) throw OutOfBounds();
	x = stack[top--];
	return true;
};

template<class T>
bool SeqStack<T>::Pop()
{
	if (IsEmpty()) throw OutOfBounds();
	top--;
	return true;
};

template<class T>
void SeqStack<T>::Output(ostream& out) const
{
	for (int i = 0, i <= top; i++)
		out << stack[i] << endl;
};

template<class T>
ostream& operator <<(ostream& out, const SeqStack<T>& x)
{
	x.Output(out);
	return out;
}
