#include <Histogram.h>

/*! \file Histogram.cpp: implements the Histogram class */

/// Evaluation operator.
/// Takes a Histogram and counts all instances of distinct strings
/// within the .histogram and stores them as a key_value_pair in the .map
void Histogram::Eval (Histogram& Hist) {
	/* for each string in histogram 
	 * find it in kvm and increment
	 * if not found, std::map::operator[] will zero-initialize
	 */
	for(auto &s : Hist.histogram) ++Hist.key_value_map[s];
}

/// Input operator. Format is string string ... str,
/// where all strings are delineated by whitespace.
/// Any other format causes the input stream to fail.
bool Histogram::Read (istream& istr, vector<string>& histogram) 
{
	string word;	// temp var for holding the word
	bool empty = true;	// the vector starts out empty 

	if(istr.fail()) return false;	// input file did not open correctly

	// store all the words in the file in a single vector
	while(istr >> word) {
		if(empty) empty = false;	// there is at least one string in the file
		histogram.push_back(word);
	}

	// if not at eof, the value was not a valid string
	if(istr.eof() != 1) {
		cerr << "Error Histogram.Read() : File contents are invalid." << endl;
		return false;
	}

	// if the file was empty we should error
	if(empty) { 
		cerr << "Error Histogram.Read() : Empty file" << endl;
		return false;
	}

  	return true;	// eof 
}

/// Write operator. 
/// Typical output operator. Takes an ostream& and a map<string, int>
/// dumps the key_value_pairs to the ostream provided
/// Erros on an empty map<string, int>
bool Histogram::Write(ostream& ostr, map<string, int>& kvm) const
{
      if (ostr.fail()) return false;	// output did not open correctly

      if(kvm.size() < 1) {
	      cerr << "Error Histogram.Write() : Empty map" << endl;
	      return false;
      }

      // dump the totals to the ostream
      for(auto s : kvm) ostr << s.first << " " << s.second << "\n";
      return true;
}
