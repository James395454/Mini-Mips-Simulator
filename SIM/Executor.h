#ifndef Executor_H
#define Executor_H   //define
#include <string>
#include "DataMemory.h"
#include <fstream>
#include "InstructionMemory.h"
using namespace std;
class executor 
{
protected:
	int out;
public:
	executor();                                                   // constructor
	executor(const executor &);                             // copy constructor
	~executor();                                                // destructor
	virtual void operate()=0;
	virtual int result()=0;
	virtual string writeoperands(ifstream & f, InstructionMemory &)=0;
	virtual void writeinputs(DataMemory &)=0;
};


#endif;
