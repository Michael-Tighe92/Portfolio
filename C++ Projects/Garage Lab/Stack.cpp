#include "Stack.h"
#include<iostream>
using namespace std;


Stack::Stack()
{
	top = 0;
}


Stack::~Stack()
{
}

//Checks if stack is empty
bool Stack::isEmpty()
{
	if (top == 0) {
		cout << "Stack is empty!" << endl;
		return true;
	}
	else
		return false;
}

//Checks if stack is full
bool Stack::isFull()
{
	if (top >= Max)
	{
		//cout << "Stack is full!" << endl;
		return true;
	}
	else
		return false;
}

//Pushes car x to the stack
void Stack::push(car x)
{
	if (top < Max)
	{
		data[top] = x;
		data[top].moves++;
		top++;
	}
	else
		cout << "Stack is full!" << endl;
}

//pops the top of stack
car Stack::pop()
{
	if (top == 0)
		cout << "Empty Stack!" << endl;
	else
	{
		top--;
		data[top].moves++;
		return data[top];
	}
}

//searches the entire stack for license
bool Stack::search(string license)
{
		for (int i = 0; i<top; i++)
		{
			if (data[i].license == license)
				return true;
		}
		return false;
}