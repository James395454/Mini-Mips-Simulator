#ifndef ASS_H
#define ASS_H    //define
#include "NEG.h"     //include "NEG"
using namespace std;

class ASS :public NEG     //Inherit from Neg
{
public:
	ASS() :NEG() {};                                                   // constructor
	ASS(const ASS & ass) : NEG(ass) {};                             // copy constructor
	~ASS();                                                // destructor
	void operate();     //perfrom Assignment
	int result();    //return result
	string writeoperands(ifstream &, InstructionMemory &);
	void writeinputs(DataMemory &);
};


#endif;

