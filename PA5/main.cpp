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
  cerr << "Usage: " << arg0 << " Exceptions.txt filename" << endl;
  cerr << "where Exceptions.txt contains 1 or more string pairs" << endl;
  cerr << "and filename contains 1 or more string values" << endl;
  cerr << "All strings should be separated by white space." << endl;
  cerr << location << endl;
  return -1;
}

int main(int argc, char** argv)
{
  // check for the correct number of arguments 
  if (argc != 3) return Usage(argv[0], "arguments != 3");
  
  ifstream infile(argv[1]);
  if (infile.fail()) return Usage(argv[0], "infile.fail()");

  ifstream istr(argv[2]);
  if (istr.fail()) return Usage(argv[0], "istr.fail()");

  Histogram h1;
  vector<Lexeme>& hist = h1.GetHist();
  unordered_map<string, string>& table = h1.GetExceptions();

  if (!h1.Read(istr, hist)) return Usage(argv[0], "Read()");
  if (!h1.ReadExceptionTable(infile, table)) return Usage(argv[0], "ReadExceptionTable()");


  h1.findCapitals(hist);
  h1.resolveAmbiguity(hist);
  
  
  istr.close();

  // stem the words using
  // Porter Algorithm #2
  Porter p0;
  p0.Eval(h1);
  
  // sort and order
  // then print
  h1.Eval(h1);
  if (!h1.Write(cout, h1.GetMap())) return Usage(argv[0], "Write()");

  return 0;
}

