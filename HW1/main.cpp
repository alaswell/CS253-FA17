/*! \file main.cpp: main function for CS253 Histogram (HW1) */
#include <Histogram.h>
#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;

/// Print the correct usage in case of user syntax error.
int Usage(char* arg0)
{
  cout << "Usage: " << arg0 << " filename" << endl;
  cout << "where file contains 1 or more values" << endl;
  cout << "where every value is an integer between 0 and 19" << endl;
  cout << "The integers should be separated by white space." << endl;
  return -1;
}

int main(int argc, char** argv)
{
  // check for the correct number of 
  if (argc != 2) return Usage(argv[0]);
  
  ifstream istr(argv[1]);
  if (istr.fail()) return Usage(argv[0]);

  Histogram h1;
  if (!h1.Read(istr)) return Usage(argv[0]);

  h1.Write(cout);
  cout << endl;
  return 0;
}

