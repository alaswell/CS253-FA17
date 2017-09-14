#include "Counter.h"
using namespace std;

Counter::Counter() 
{
	for(int i = 0; i < 20; i++)
		result[i] = 0;  	
} 

void Counter::Print(ostream& ostr) const
{
	for(int i = 0; i < 20; i++)
	{
		ostr << i << " " << result[i] << endl;
	}
}

bool Counter::Read(istream& istr) 
{
	int a;
	istr >> a;
	int total = 0;
 
  	while(!istr.fail() && 0 <= a && a <= 19)
  	{
		result[a]++;
		istr >> a;
		total++;
  	}

	// if not at eof, the value was not a valid integer
	if(total == 0 || 
		(a < 0 || a > 19) ||
		(istr.fail() && !istr.eof()) )
		return false;

	return true;  
}


