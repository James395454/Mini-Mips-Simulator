#ifndef JMP_H
#define JMP_H  //define
#include "Executor.h"   //include parent
using namespace std;

class JMP :public executor   //inherit from parent
{
protected:
	int a1;    //address
	string in;
public:
	JMP();                                                  // constructor
	JMP(const JMP &);                             // copy constructor
	~JMP();                                                // destructor
	void operate();    //operate
	int result();    //result
	string writeoperands(ifstream & , InstructionMemory & );
	void writeinputs(DataMemory &);
};


#endif;

