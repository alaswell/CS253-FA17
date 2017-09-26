#include <Reader.h>
#include <sstream>
using std::istringstream;
#include <iostream>

Reader::Reader(const string& input)
{
	std::cout << "Reader Constructor" << std::endl;
  istringstream istr(input);
  string str;
  istr >> str;
  while(!istr.fail()) {
    ht.Add(str);
    istr >> str;
  }
}

Reader::~Reader()
{
	std::cout << "     Reader Destructor" << std::endl;
}

int Reader::Compare(string comp_str) 
{
	std::cout << "Reader Compare()" << std::endl;
  int ctr = 0;
  istringstream istr(comp_str);
  string str;
  istr >> str;
  while(!istr.fail()) {
    if (ht.Contains(str)) ctr++;
    istr >> str;
  }
  return ctr;
}
