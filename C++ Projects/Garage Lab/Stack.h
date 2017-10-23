#pragma once
#define Max 10 //Max size of the stack
#include<string>
using namespace std;
//car struct
struct car {
	string license;
	int moves;
};
class Stack
{
public:
	//Default constructor
	Stack();
	~Stack();
	//Methods
	void push(car x);
	car pop();
	bool isEmpty();
	bool isFull();
	bool search(string license);
private:
	car data[Max];
	int top;
};
