#include "Counter.h" 
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{

  	if (argc != 2) return -1;
  
  	ifstream istr(argv[1]);
  	if (istr.fail()) return -1;

  	Counter p1;
  	if (!p1.Read(istr)) return -1;
 
  	p1.Print(cout);
  	return 0;
}




