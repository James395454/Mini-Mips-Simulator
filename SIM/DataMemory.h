#ifndef DATAMEMORY_H    
#define DATAMEMORY_H   //define
#include<string>
#include <map>
using namespace std;



class DataMemory
{
private:
	map<string, int> data;   //declare data memory as a map with string as an index and int as stored value
	int MaxSize,Size;
public:
	DataMemory();                                                   // constructor
	DataMemory(const DataMemory &);                             // copy constructor
	~DataMemory();                                                // destructor
	int retrieve(string);                             // retrieve from data memory
	void insert(int,string);                            // write in Data Memory
	void PrintData();                                      //print Data Memory
};


#endif;