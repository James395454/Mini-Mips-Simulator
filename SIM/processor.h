#ifndef processor_H  //define
#define processor_H
#include "DataMemory.h"  //include datamemory
#include <string>
#include "InstructionMemory.h"  //include instruction memory
#include "WRITE.h"   //include output
#include "Executor.h"
#include <iostream>
#include <mutex>
using namespace std;

class processor   //inherit from instrmem and datamem
{
private:
	int count;
	map<string, executor*> ex;
	mutex mu;
public:
	processor() {  };                                                   // constructor
	processor(const processor &c) { count = 0; };                             // copy constructor
	~processor();                                                // destructor
	void compile(string filename,InstructionMemory &,DataMemory & );   //write from file to instr memory
	int execute(string, int,string,DataMemory &);  //execute instructions
};


#endif;
