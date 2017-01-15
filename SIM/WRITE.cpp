#include "WRITE.h"  //include header file
#include <iostream>
#include <string>
using namespace std;
WRITE::~WRITE()                                               // destructor
{

}
void WRITE::operate()  //operate
{
	out = a1;
	cout <<"Part of program output: "<< out << endl;
}
int WRITE::result()   //print output
{
	return out;
}

string WRITE::writeoperands(ifstream & f, InstructionMemory & I_Mem)  //write one operand
{
	in = "";
	int count = 0;
	string instr = "";
	string temp = "";
	getline(f, instr);
	bool p = false;
	for (int i = 0;i < instr.length();i++)
	{
		if (instr[i] == ' ')
			p = true;
		if (p)
			temp += instr[i];
	}
	instr = temp;
	for (int i = 0;i < instr.length();i++)
	{
		if ((instr[i] != ' ') && (instr[i] != ','))
			in += instr[i];
	}
	string addtomem = "WRITE ";addtomem += in;
	if (!I_Mem.find(addtomem))
	I_Mem.writetomemory(addtomem);
	return in;
}
void WRITE::writeinputs(DataMemory &D_Mem)  //write integer value of "in" in i
{
	int sign = 1, i;
	if (in[0] == '-')  // if negative
	{
		string temp = "";
		for (int i = 1;i < in.length();i++)  //remove negative sign from variable name
			temp += in[i];
		in = temp;
		sign = -1;
	}
	if (isdigit(in[0]))    //if constant
	{

		i = stoi(in)*sign;
	}
	else
	{
		if (D_Mem.retrieve(in) == NULL)   //retrieve value from data memory
			i = 0;
		else i = D_Mem.retrieve(in)*sign;
	}
	a1 = i;
}
