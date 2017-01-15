#include "DataMemory.h"
#include <iostream>
using namespace std;

DataMemory::DataMemory()   //constructor
{
	MaxSize = 1024;    //set maxsize
	Size = 0;     //set size
}

DataMemory::~DataMemory()    //destructor
{
}
DataMemory::DataMemory(const DataMemory &c)   //copy constructor
{
	data = c.data;
	Size = c.Size;
	MaxSize = 1024;
}
int DataMemory::retrieve(string variable)    //retrieve an address
{
	return data[variable];
}

void DataMemory::insert(int value, string variable)   //insert in data memory
{ 	//cout << "value "<<value<<endl;
	if (Size < MaxSize)    //make sure we dont write more than 1024 addresses
	{
		data[variable] = value;  //insert in map
		Size++;   //increment size
	}
	else throw out_of_range("Data Memory is full");
}

void DataMemory::PrintData()
{
	for (auto x : data)   //loop on map and print one by one
	{
		cout << x.first << ": " << x.second << endl;
	}
}