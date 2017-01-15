#ifndef WRITE_H  
#define WRITE_H  //define
#include "READ.h"
using namespace std;

class WRITE:public executor   //inherit from read
{
private:
	int out,a1;
	string in;
public:
	WRITE() { };                                                  // constructor
	WRITE(const WRITE &c) { in = c.in;out = c.out;a1 = c.a1; };                             // copy constructor
	~WRITE();                                                // destructor
	void operate();  //operate
	int result();  //print output
	string writeoperands(ifstream &, InstructionMemory &);
	void writeinputs(DataMemory &);
};


#endif;


