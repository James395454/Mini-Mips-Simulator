#include "JMP0.h"   //include header
using namespace std;
#include <iostream>
JMP0::~JMP0()                                               // destructor
{

}
void JMP0::operate()
{
	if ((a1 < 0) || (a1>1023))
		throw invalid_argument("error invalid jump address, terminating");
	else if (!isalpha(in22[0]))   //make sure its an address and not a constant
		throw invalid_argument("Jump address can't be a constant, terminating");
	if (in1 == 0)     //if in1==0 then set out to a1
		out = a1;
	else out = -2;   //out=-2 means that we wont jump
}
int JMP0::result()  //return result
{
	return out;
}
string JMP0::writeoperands(ifstream & f, InstructionMemory & I_Mem)  //write 3 operands
{
	int count = 0;
	in11 = "";
	in22 = "";
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
	for (int i = 0;i < instr.length();i++)  //write variable name in "in"
	{
		if ((instr[i] != ' ') && (instr[i] != ',') && (!count))
			in11 += instr[i];
		else if (instr[i] == ',')
			count = 1;
		else if ((count) && (instr[i] != ' '))
			in22 += instr[i];
	}
	string addtomem = "JMP0 ";addtomem += in11;addtomem += ",";addtomem += in22;
	if (!I_Mem.find(addtomem))
		I_Mem.writetomemory(addtomem);

	return in22;
}
void JMP0::writeinputs(DataMemory &D_Mem)  //write integer values of variables
{
	int  i1, i2, sign = 1;   //sign
	if (in11[0] == '-')  //if negative sign
	{
		string temp = "";
		for (int i = 1;i < in11.length();i++)   //remove negative sign from variable name
			temp += in11[i];
		in11 = temp;
		sign = -1;  //sign is negative
	}
	if (isdigit(in11[0]))  //if constant
	{

		i1 = stoi(in11)*sign;   //convert string to integer and multiply by sign
	}
	else
	{
		if (D_Mem.retrieve(in11) == NULL)   //retrieve value from data memory
			i1 = 0;
		else i1 = D_Mem.retrieve(in11)*sign;
	}
	sign = 1;
	//same for second variable
	if (in22[0] == '-')
	{
		string temp = "";
		for (int i = 1;i < in22.length();i++)
			temp += in22[i];
		in22 = temp;
		sign = -1;
	}
	if ((in22[0] == '-') && (isdigit(in22[1])))
	{
		string temp = "";
		for (int i = 1;i < in22.length();i++)
			temp += in22[i];
		in22 = temp;
		i2 = -stoi(in22);
		sign = -1;
	}
	else if (isdigit(in22[0]))
	{
		i2 = stoi(in22)*sign;
	}
	else
	{
		if (D_Mem.retrieve(in22) == NULL)    //retrieve value from data memory
			i2 = 0;
		else i2 = D_Mem.retrieve(in22)*sign;
	}
	in1 = i1;
	a1 = i2;
}