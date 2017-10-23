#include "Garage.h"
#include<iostream>
using namespace std;


Garage::Garage()
{
}

Garage::~Garage()
{
}

void Garage::Arrival(car V)
{
	//Checks to see if lane1 is full
	if (lane1.isFull() == false)
	{
		//car V gets push into the lane1 stack
		lane1.push(V);
		cout << V.license << " Has arrived in lane 1" << endl;
		//V.moves gets incremented to keep track of how many times the car has been moved
		V.moves++;
	}
	//Checks to see if lane2 is full
	else if (lane2.isFull() == false)
	{
	    //car V gets push into the lane2 stack
		lane2.push(V);
		cout << V.license << " Has arrived in lane 2" << endl;
		//V.moves gets incremented to keep track of how many times the car has been moved
		V.moves++;
	}
	else
		//Cars can't be parked on the street
		cout << "Sorry, you can't park in either lanes because they are both full" << endl;
}

void Garage::Departure(string license)
{
	//Our temp object
	car temp;
	//Counters that check how much cars are in which stack when being moved
	int lane1_Counter = 0;
	int lane2_Counter = 0;
	int street_Counter = 0;
	//Searches lane1 to see if the vehicle's license is located within the stack
	if (lane1.search(license) == true)
	{
		//While loop continues as long as lane1 is not empty
		while (lane1.isEmpty() == false)
		{
			//temp gets data from pop
			temp = lane1.pop();
			if (temp.license == license)
			{
				cout << temp.license << " Has departed lane 1 and has been moved: " << temp.moves << " times!" << endl;
				break;
			}
			else
			{
				//temp is pushed into lane1 stack
				lane1.push(temp);
				//Checks to see if lane 2 is full
				if (lane2.isFull() == false)
				{
					lane2_Counter++;
					//car gets moved from lane1 to lane2
					lane2.push(lane1.pop());
					cout << temp.license << " Has moved from lane 1 to lane 2!" << endl;
				}
				//Condition when lane2 is full
				else if (lane2.isFull() == true)
				{
					street_Counter++;
					street.push(lane1.pop());
					cout << temp.license << " Has moved from lane 1 to street!" << endl;
				}
				//If both lane2 and street is full
				if (lane2.isFull() == true && street.isFull() == true)
					cout << "Both lane 2 and street are full!" << endl;
			}
		}
		//gets anything from street stack and returns it to lane1 stack
		while (street_Counter>0)
		{
			street_Counter--;
			lane1.push(street.pop());
		}
		//gets anything from lane2 stack and returns it to lane1 stack
		while (lane2_Counter>0)
		{
			lane2_Counter--;
			lane1.push(lane2.pop());
		}
	}

	//The code below is the same as above except we are dealing with lane2 stack
	else if (lane2.search(license) == true)
	{
		while (lane2.isEmpty() == false)
		{
			temp = lane2.pop();
			if (temp.license == license)
			{
				cout << temp.license << " Has departed lane 2 and has been moved: " << temp.moves << " times!" << endl;
				break;
			}
			else
			{
				lane2.push(temp);
				if (lane1.isFull() == false)
				{
					lane1_Counter++;
					lane1.push(lane2.pop());
					cout << temp.license << " Has moved from lane 2 to lane 1!" << endl;
				}
				else if (lane1.isFull() == true)
				{
					street_Counter++;
					street.push(lane2.pop());
					cout << temp.license << " Has moved from lane 2 to street!" << endl;
				}
				if (lane1.isFull() == true && street.isFull() == true)
					cout << "Both lane 1 and street are full!" << endl;
			}
		}

		while (street_Counter>0)
		{
			street_Counter--;
			lane2.push(street.pop());
		}
		while (lane1_Counter>0)
		{
			lane1_Counter--;
			lane2.push(lane1.pop());
		}
	}

	else
		//This confirms that the car does not exist within either lane1 or lane2 stack
		cout<<license<<" was not found in either lane 1 or lane 2"<<endl;
}