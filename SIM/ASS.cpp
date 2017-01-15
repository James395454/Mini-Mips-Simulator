#include "ASS.h"
using namespace std;
ASS::~ASS()                                               // destructor
{
}
void ASS::operate()       //perfrom assignment
{
	out = in;       //assign in to out
}
int ASS::result()
{
	return out;    //return out
}
string ASS::writeoperands(ifstream & f, InstructionMemory & I_Mem) //write 2 operands
{
	int count = 0;
	outs = "";
	in11 = "";
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
			outs += instr[i];
	}
	string addtomem = "ASS ";addtomem += in11;addtomem += ",";addtomem += outs;
	if(!I_Mem.find(addtomem))
	I_Mem.writetomemory(addtomem);
	return outs;
}
void ASS::writeinputs(DataMemory &D_Mem)  //write integer value of "in" in i
{
	int sign = 1, i;
	if (in11[0] == '-')  // if negative
	{
		string temp = "";
		for (int i = 1;i < in11.length();i++)  //remove negative sign from variable name
			temp += in11[i];
		in11 = temp;
		sign = -1;
	}
	if (isdigit(in11[0]))    //if constant
	{

		i = stoi(in11)*sign;
	}
	else
	{
		if (D_Mem.retrieve(in11) == NULL)   //retrieve value from data memory
			i = 0;
		else i = D_Mem.retrieve(in11)*sign;
	}
	in = i;
}