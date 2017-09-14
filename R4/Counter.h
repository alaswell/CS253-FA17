#ifndef COUNTER_H
#define COUNTER_H

#include<iostream>
#include<fstream>
using namespace std;

class Counter {
public:
	Counter();
	void Print(ostream& ostr) const;
	bool Read(istream& istr); 

private:
	int result[20];
  
};


#endif 
