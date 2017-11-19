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
#include <sstream>
using std::stringstream;

/// Print the correct usage in case of user syntax error.
int Usage(char* arg0, const char* location)
{
  cerr << "Usage: " << arg0 << " filename1 filename2 min max" << endl;
  cerr << "where filename1 contains one or more string values" << endl;
  cerr << "and filename1 contains a list of filenames to be read" << endl;
  cerr << "All strings should be separated by white space." << endl;
  cerr << "Finally, min and max outline a range for reading level" << endl;
  cerr << location << endl;
  return -1;
}

int main(int argc, char** argv)
{
  // check for the correct number of arguments 
  if (argc < 5) return Usage(argv[0], "arguments != 1");

  vector<string> filenames; 	// temp vector for holding the names of the files
  string filename;

  // parse the file of filenames
  ifstream fnames(argv[2]);
  if (fnames.fail()) return Usage(argv[0], "fnames.fail()");
  while(fnames >> filename) {
	filenames.push_back(filename);
  }

  // if not at eof, value was not a valid string (filename)
  if(fnames.eof() != 1) {
	  cerr << "Error " << argv[2] << ".Read() : File contents are invalid." << endl;
	  return -1;
  }
  fnames.close();

  // exceptions
  ifstream infile(filenames[0]);
  if (infile.fail()) return Usage(argv[0], "infile.fail()");

  Cluster c0;
  unordered_map<string, string> table = c0.GetExceptions();
  if(!c0.Read(infile, table)) return Usage(argv[0], "Read Exception Table");
  infile.close();

  // min and max CLIndex
  double minIndex, maxIndex;

  // get the minIndex
  string input = argv[3];
  stringstream ss = stringstream(input);
  ss >> minIndex;
  if (ss.fail()) return Usage(argv[0], "Not a valid double minIndex");

  // get the maxIndex
  input = argv[4];
  ss = stringstream(input);
  ss >> maxIndex;
  if (ss.fail()) return Usage(argv[0], "Not a valid double maxIndex");

  // is this range valid 
  if (minIndex > maxIndex) return Usage(argv[0], "Not a valid range (min > max)");

  /* util class for parsing */
  Porter p0;
  ColemanLiau cl0;

/* begin histograms */

  // get the first file/histogram
  ifstream istr(argv[1]);	
  if (istr.fail()) return Usage(argv[0], "istr.fail()");

  Histogram h;
  vector<Lexeme>& hist = h.GetHist();

  if (!h.Read(istr, hist)) return Usage(argv[0], "Histogram::Read()");
  istr.close();

  // append '+' to ambiguous capital words  
  h.findCapitals(hist);

  // get the Coleman-Liau index 
  if (!cl0.Eval(h)) return Usage(argv[0], "ColemanLiau::Eval()");

  // clean up the words a bit
  h.resolveAmbiguity(hist);
  
  // stem the words using
  // Porter Algorithm #2
  p0.Eval(h, table);
  
  // sort and order
  h.Eval();
  
  // add to the cluster
  c0.add(h);

  // now the rest of them
  for(vector<string>::iterator it = ++filenames.begin(); it != filenames.end(); ++it) {
	ifstream istr(*it);
	if (istr.fail()) return Usage(argv[0], "istr.fail() filenames vector");

	Histogram h1;
	ColemanLiau cl1;
	vector<Lexeme>& hist1 = h1.GetHist();

	if (!h1.Read(istr, hist1)) return Usage(argv[0], "Histogram1::Read()");
	istr.close();


  	// append '+' to ambiguous capital words  
	  h1.findCapitals(hist1);

	  // get the Coleman-Liau index 
	  if (!cl1.Eval(h1)) return Usage(argv[0], "ColemanLiau::Eval()");
	  h1.SetIndex(cl1.getIndex());

	  // clean up the words a bit
	  h1.resolveAmbiguity(hist1);
  
	  // stem the words using
	  // Porter Algorithm #2
	  p0.Eval(h1, table);
  
	  // sort and order
	  h1.Eval();
  
	  // add to the cluster
	  c0.add(h1);
  }
/* end histograms */


  vector<Histogram>& cluster = c0.GetCluster();
  map<string, double>& IDF = c0.GetMap();
  IDF = c0.GetInverseDocumentFrequencies(cluster, IDF);

  double val, max = 0.0;
  int i, location = 0;
  for(vector<Histogram>::iterator h = ++cluster.begin(); h != cluster.end(); ++h) {
	  ++i;
	  if(h->GetIndex() >= minIndex && h->GetIndex() <= maxIndex) {
		  val = c0.Compare(cluster[0], cluster[i], IDF);
		  if(max <= val) {
			max = val;
		  	location = i;
		  }
	  }	  
  }
  
  if(location == 0) return Usage(argv[0], "No documents with provided range");
  else std::cout << filenames[location] << endl;

  return 0;
}

