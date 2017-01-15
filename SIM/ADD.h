#ifndef ADD_H    
#define ADD_H    //define
#include "Executor.h"   //include parent class

#include <string>
using namespace std;

class ADD :public executor     //inherit from parent class
{
protected:
	int in1, in2;      //input 
	string in11,in22, outs;

public:
	ADD();                                                   // constructor
	ADD(const ADD &);                             // copy constructor
	~ADD();                                                // destructor
	void operate();     //perfrom addition
	int result();     //result of addition
	string writeoperands(ifstream & ,InstructionMemory &);
	void writeinputs(DataMemory & );
};


#endif;
