#include "LE.h"   //include header file
using namespace std;

LE::~LE()                                               // destructor
{

}
void LE::operate()   //operate
{
	if (in1 <= in2)    //if in1<=in2 then out=1 else out=0
		out = 1;
	else out = 0;
}
int LE::result()   //return result
{
	return out;
}
void LE::setvalues(int a,int b)
{
	in1 = a;
	in2 = b;
}
string LE::writeoperands(ifstream & f, InstructionMemory & I_Mem)  //write 3 operands
{
	outs = "";
	in11 = "";
	in22 = "";
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
		if ((instr[i] != ' ') && (instr[i] != ',') && (!count))
			in11 += instr[i];
		else if (instr[i] == ',')
			count++;
		else if ((count == 1) && (instr[i] != ' '))
			in22 += instr[i];
		else if ((count == 2) && (instr[i] != ' '))
			outs += instr[i];
	}
	string addtomem = "LE ";addtomem += in11;addtomem += ",";addtomem += in22;addtomem += ",";addtomem += outs;
	if (!I_Mem.find(addtomem))
	I_Mem.writetomemory(addtomem);
	return outs;
}
void LE::writeinputs(DataMemory &D_Mem)  //write integer values of variables
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
	in2 = i2;

}