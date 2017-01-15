#ifndef MUL_H
#define MUL_H   //define
#include "ADD.h"  //include ADD
using namespace std;

class MUL :public ADD   //inherit from ADD
{
public:
	MUL() :ADD() {  };                                                   // constructor
	MUL(const MUL & mul) :ADD(mul) {};                             // copy constructor
	~MUL();                                                // destructor
	void operate();  //operate
	int result();   //result
	void setvalues(int,int);
	string writeoperands(ifstream &, InstructionMemory &);
	void writeinputs(DataMemory &);
};
#endif;


