#include "processor.h"  //include header file
#include <iostream>
#include <map>
#include <fstream>
#include "LE.h"       //include LE
#include "ASS.h"      //include ASS
#include "JMP0.h"     //include JMP0
#include "WRITE.h"    //include WRITE
using namespace std;
processor::~processor()                                              // destructor
{
}
void processor::compile(string filename, InstructionMemory & I_Mem, DataMemory & D_Mem)
{

	ex["ADD"] = new ADD();
	ex["MUL"] = new MUL();
	ex["LE"] = new LE();
	ex["ASS"] = new ASS();
	ex["NEG"] = new NEG();
	ex["JMP0"] = new JMP0();
	ex["JMP"] = new JMP();
	ex["READ"] = new READ();
	ex["WRITE"] = new WRITE();

	string in;   //string to read from file
	ifstream f;  //declare an ifstream
	f.open(filename);
	int *order = new int[1024], j = 1;   //order of instructions executed
	int instr_num = 0, t = 0;
	order[0] = 0;
	bool done = false;
	string instrtype, instr = "", writeto;
	//cout << "***********    Program Output:   ************************" << endl;
	while (!f.eof())//till end of file  
	{
		instrtype = "";
		f >> instrtype;
		if (instrtype != "HALT")
		{
			mu.lock(); //prevent any other thread from reading from data memory
			cout << filename << " is reading from data memory" << endl;
			writeto = ex[instrtype]->writeoperands(f, I_Mem);   //write variable names 
			mu.unlock(); //allow other threads to write in data memory
			mu.lock();  //prevent any other thread from writing in data memory
			cout << filename <<" is writing in data memory"<< endl;
			ex[instrtype]->writeinputs(D_Mem);   //write integers in variables
			mu.unlock(); //allow other threads to write in data memory
		}
		if (instr_num == -2)
		{
			instr_num = t;
		}
		int k = instr_num;
		if (t == instr_num)
		{
			instr_num = execute(instrtype, instr_num, writeto, D_Mem);             //execute instructions one by one
			if (instr_num == -1)      //if HALT
			{
				order[j++] = k;
				I_Mem.writetomemory("HALT");
				break;
			}
			else
			{
				//cout << instrtype << endl;
				if (instr_num == -3)
					instr_num = t;
				order[j++] = instr_num + 1;  //add current instruction being executed (address)
			}
			instr_num++;

		}

		if ((instr_num < t) && (instr_num != -2))   //if jumping backwards
		{
			f.clear();
			f.seekg(0, f.beg);
			string trash;
			for (int i = 0;i < instr_num;i++)
			{
				getline(f, trash);
			}
			t = instr_num;
		}
		else
			t++;

	}
	count++;
	cout <<endl<<"**********"<< filename<<" Is done executing***********"<< endl << endl;	
}
int processor::execute(string instr, int nextaddress, string writeto, DataMemory & D_Mem)  //execute all instructions
{
	if (instr == "HALT")
		return -1;
	ex[instr]->operate();
	if ((instr == "JMP0") || (instr == "JMP"))
	{
		nextaddress = ex[instr]->result() - 1;
	}
	if (instr != "JMP0")
		D_Mem.insert(ex[instr]->result(), writeto);  //insert in data memory

	return nextaddress;
}
