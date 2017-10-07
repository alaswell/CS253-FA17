/*! \file main.cpp: main function for CS253 Histogram (HW1) */
#include <Histogram.h>
#include <Porter.h>
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
#include <fstream>
using std::ifstream;

/// Print the correct usage in case of user syntax error.
int Usage(char* arg0, const char* location)
{
  cerr << "Usage: " << arg0 << " filename" << endl;
  cerr << "where file contains 1 or more values" << endl;
  cerr << "where every value is a string" << endl;
  cerr << "The strings should be separated by white space." << endl;
  cerr << location << endl;
  return -1;
}

int main(int argc, char** argv)
{
  // check for the correct number of arguments 
  if (argc != 2) return Usage(argv[0], "arguments != 2");
  
  ifstream istr(argv[1]);
  if (istr.fail()) return Usage(argv[0], "istr.fail()");

  Histogram h1;
  if (!h1.Read(istr, h1.GetHist())) return Usage(argv[0], "Read()");
  h1.findCapitals(h1.GetHist());
//  for(int i = 0; i < h1.GetHist().size(); i++) std::cout <<  h1.GetHist().at(i).getString() << std::endl;
  h1.Eval(h1);
  
  if (!h1.Write(cout, h1.GetMap())) return Usage(argv[0], "Write()");
  
  istr.close();

  //Porter p0;
  //p0.Eval(h1);
  return 0;
}

