#include "InstructionMemory.h"
#include <iostream>
using namespace std;

InstructionMemory::InstructionMemory()   //constructor
{
	size = 0;
	MAXSIZE = 1024;
	mem = new string[1024];   //array of strings
	for (int i = 0; i < 1024; i++)   //set all instructions to an empty string
		mem[i] = "";
}
InstructionMemory::~InstructionMemory()   //destructor
{
	delete[] mem;   //delete array
}
InstructionMemory::InstructionMemory(const InstructionMemory &c)   //copy constructor
{
	size = c.size;
	MAXSIZE = c.MAXSIZE;
		mem = c.mem;
}
string InstructionMemory::retrieveinst(int pos)   //retrieve an instruction
{
	if ((pos>=0)&&(pos<MAXSIZE))   //make sure valid instruction address
	return mem[pos];    //return instruction
	else throw out_of_range("Invalid index for instruction memory");
}
bool InstructionMemory::find(string instr)
{
	for (int i = 0;i < size;i++)
		if (mem[i] == instr)
			return true;
	return false;
}
void InstructionMemory::writetomemory(string inst)
{
	
	cout << size << " " << inst << endl;
	if (size < MAXSIZE)   //make sure we dont exceed 1024 instructions		
		mem[size++] = inst;
	else throw out_of_range("Instruction Memory is full");
	
	
}
int InstructionMemory::SIZE()
{
	return size;
}
void InstructionMemory::PrintInstructions()   //print instruction memory
{
	for (int i = 0; i < size; i++)
	{
		cout << mem[i] << endl;
	}
}
