/*! \file main.cpp: main function for CS253 Histogram (HW1) */
#include <Cluster.h>
#include <Histogram.h>
#include <Porter.h>
#include <ColemanLiau.h>
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
  cerr << "where filename contains 1 or more string values" << endl;
  cerr << "All strings should be separated by white space." << endl;
  cerr << location << endl;
  return -1;
}

int main(int argc, char** argv)
{
  // check for the correct number of arguments 
  if (argc < 2) return Usage(argv[0], "arguments != 1");
/*  
  // exceptions
  ifstream infile(argv[1]);
  if (infile.fail()) return Usage(argv[0], "infile.fail()");


  Cluster c0;
  unordered_map<string, string> table = c0.GetExceptions();
  if(!c0.Read(infile, table)) return Usage(argv[0], "Read Exception Table");
*/

  Porter p0;
  ColemanLiau cl0;

  /* begin histogram(s) */
//  for(int i = ; i < argc; i++) {
//	ifstream istr(argv[i]);
	ifstream istr(argv[1]);	
	if (istr.fail()) return Usage(argv[0], "istr.fail()");

	Histogram h;
	vector<Lexeme>& hist = h.GetHist();

	if (!h.Read(istr, hist)) return Usage(argv[0], "Histogram::Read()");
  	istr.close();

	h.findCapitals(hist);

	// get the Coleman-Liau index 
	if (!cl0.Eval(h)) return Usage(argv[0], "ColemanLiau::Eval()");
/*
	// clean up the words a bit
	h.resolveAmbiguity(hist);
  
	
	// stem the words using
	// Porter Algorithm #2
	p0.Eval(h, table);
  
	// sort and order
	// then print
	h.Eval();
	c0.add(h);

  }
*/
  /* end histograms */
/*
  vector<Histogram>& cluster = c0.GetCluster();
  map<string, double>& map = c0.GetMap();
  map = c0.GetInverseDocumentFrequencies(cluster, map);

  std::cout << c0;
*/
  std::cout << cl0 << endl;
  return 0;
}

