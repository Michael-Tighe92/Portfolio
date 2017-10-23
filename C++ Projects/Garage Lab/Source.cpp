//Michael Tighe
//CSC 326 Garage Lab
#include<iostream>
#include<string>
#include<fstream>
#include"Garage.h"
using namespace std;
int main()
{
	//Creates object out of car struct
	car Vehicle;
	//Creates object out of Garage class
	Garage test;
	//Keeps track of whether Vechicle is arriving or departing 
	char arrival;
	ifstream infile;
	//Opens file
	infile.open("Test.txt");
	//Checks to see if file was opened
	if(!infile)
	{
		cout<<"Error! Could not find the file!"<<endl;
		return 0;
	}
	//Goes through the entire file
	while (!infile.eof())
	{
		infile >> arrival >> Vehicle.license;
		Vehicle.moves=0;
		if (arrival == 'A')
			test.Arrival(Vehicle);
		else
			test.Departure(Vehicle.license);
	}
	return 0;

}
