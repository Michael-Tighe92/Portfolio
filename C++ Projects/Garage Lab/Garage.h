#pragma once
#include<string>
#include"Stack.h"
using namespace std;
class Garage
{
public:
	//Default Constructor
	Garage();
	~Garage();
	//Methods
	void Arrival(car);
	void Departure(string);
	bool Search(string);
private:
	//Creates an object out of the class Stack
	Stack lane1,lane2,street;
};
