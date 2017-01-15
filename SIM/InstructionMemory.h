#ifndef INSTRUCTIONMEMORY_H
#define INSTRUCTIONMEMORY_H
#include <string>

using namespace std;


class InstructionMemory
{

protected:
	string *mem;                                                // declare Instruction Memory Array
	int size, MAXSIZE;    //current size of instruction memory, maxsize of instruction memory

public:
	InstructionMemory();                                             // constructor
	InstructionMemory(const InstructionMemory &);                // copy constructor  
	~InstructionMemory();                                           // destructor
	string retrieveinst(int);                            // read from Instruction Memory
	void writetomemory(string);                                      // write in Instruction Memory
	void PrintInstructions();                                       // print Instruction Memory
	bool find(string);
	int SIZE();
};

#endif;