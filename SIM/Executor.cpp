#include "Executor.h"  //include header file
using namespace std;

executor::executor()                                                   // constructor
{
	out = 0;
}
executor::executor(const executor & c)                          // copy constructor
{
	out = c.out;
}
executor::~executor()                                               // destructor
{

}

