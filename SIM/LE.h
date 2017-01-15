#ifndef LE_H
#define LE_H   //define
#include "MUL.h"   //include MUL
using namespace std;

class LE :public MUL    //inherit from MUL
{
public:
	LE () :MUL() {};                                                   // constructor
	LE(const LE & le) :MUL(le) {};                             // copy constructor
	~LE();                                               // destructor
	void operate();   //operate
	int result();   //return result
	void setvalues(int,int);
	string writeoperands(ifstream &, InstructionMemory &);
	void writeinputs(DataMemory &);
};


#endif;
