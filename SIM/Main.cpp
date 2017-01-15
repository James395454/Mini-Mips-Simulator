#include <iostream>
#include <string>
#include <Thread>
#include "processor.h"  //include main class
#include "InstructionMemory.h"
#include "DataMemory.h"
using namespace std;
void main()
{
	InstructionMemory I1, I2, I3, I4;
	DataMemory D_Mem;
	processor p; // Declare a processor

	thread t1(&processor::compile, &p, "Program1.txt", (I1) , std::ref( D_Mem));  //pass program and instruction memory to processor running on thread t1	
	thread t2(&processor::compile, &p, "Program2.txt", I2, std::ref(D_Mem));
	thread t3(&processor::compile, &p, "Program3.txt", I3, std::ref(D_Mem));  //pass program and instruction memory to processor running on thread t1	
	thread t4(&processor::compile, &p, "Program4.txt", I4, std::ref(D_Mem));
	
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	cout << endl << "***********    Printing Data Memory:   ************************" << endl << endl;
	D_Mem.PrintData();   //print data memory
	cout << endl;
	system("pause");
}