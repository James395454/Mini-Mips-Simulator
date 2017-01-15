#ifndef NEG_H
#define NEG_H
#include "Executor.h"   //include parent
using namespace std;

class NEG :public executor   //inherit from parent
{
protected:
	int in;
	string in11, outs;
public:
	NEG();                                                   // constructor
	NEG(const NEG &);                             // copy constructor
	~NEG();                                                // destructor
	void operate();   //operate
	int result();   //result
	string writeoperands(ifstream & , InstructionMemory & );
	void writeinputs(DataMemory &);
};


#endif;

