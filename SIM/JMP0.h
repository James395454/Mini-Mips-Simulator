#ifndef JMP0_H
#define JMP0_H  //define
#include "JMP.h"   //include header file
using namespace std;

class JMP0 :public JMP   //inherit from JMP
{
private:
	int in1;     //address
	string in11,in22;
public:
	JMP0() :JMP() { in1 = 0; };                                                  // constructor
	JMP0(const JMP0 &c):JMP(c)                             // copy constructor
	{
		in1 = c.in1;
	}
	~JMP0();                                                // destructor
	void operate();   //operate
	int result();    //result
	string writeoperands(ifstream & , InstructionMemory & );
	void writeinputs(DataMemory &);
};


#endif;

