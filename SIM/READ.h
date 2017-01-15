#ifndef READ_H
#define READ_H
#include "JMP.h"  //include header file
using namespace std;

class READ :public JMP   //inherit from JMP
{
private:
	string outs;
public:
	READ() :JMP() {  };                                                  // constructor
	READ(const READ &c) :JMP(c) {};                             // copy constructor
	~READ();                                                // destructor
	void operate();  //operate
	int result();  //result
	string writeoperands(ifstream & f, InstructionMemory & );
	void writeinputs(DataMemory &);
};


#endif;


