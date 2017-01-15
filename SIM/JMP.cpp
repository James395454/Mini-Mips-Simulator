#include "JMP.h"
using namespace std;
JMP::JMP()                                                  // constructor
{
	a1 = 0;
}
JMP::JMP(const JMP & c)                          // copy constructor
{
	a1 = c.a1;
	out = c.out;
}
JMP::~JMP()                                               // destructor
{

}
void JMP::operate()   //operate
{
	if ((a1<0) || (a1>1023))
		throw invalid_argument("error invalid jump address, terminating");
	else if (!isalpha(in[0]))   //make sure its an address and not a constant
		throw invalid_argument("Jump address can't be a constant, terminating");
	out = a1;  //set out to address
}
int JMP::result()  //return result
{
	return out;
}
string JMP::writeoperands( ifstream & f, InstructionMemory & I_Mem)  //write one operand
{

	int count = 0;
	in = "";
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
	string addtomem = "JMP ";addtomem += in;
	if (!I_Mem.find(addtomem))
	I_Mem.writetomemory(addtomem);
	return in;
}
void JMP::writeinputs(DataMemory &D_Mem)  //write integer value of "in" in i
{
	int sign = 1,i;
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

