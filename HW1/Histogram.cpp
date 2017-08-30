#include <Histogram.h>

/*! \file Histogram.cpp: implements the Histogram class */

/// Input operator. Format is int int ... int,
/// where all integers are in the range 0-19.
/// Any other format causes the input stream to fail.
bool Histogram::Read (istream& istr, vector<int>& histogram) 
{
	int num;	// temp var for holding the number
	bool empty = true;	// the vector starts out empty 

	if(istr.fail()) return false;	// input file did not open correctly

	while(istr >> num) {
		empty = false;	// there is at least one integer in the file

		if(num < 0 || num > 19) {
			// must be in range 0-19
			cerr << "Error Message Histogram.Read() : Integer out of range '"
				<< num << "'" << endl;
			return false;
		}
		histogram.at(num)++;
	}

	// if not at eof, the value was not a valid integer
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

bool Histogram::Write(ostream& ostr, vector<int>& histogram) const
{
      if (ostr.fail()) return false;	// output did not open correctly

      if(histogram.size() < 1) {
	      cerr << "Error Histogram.Write() : Empty vector 'histogram'" << endl;
	      return false;
      }

      // dump the totals to the ostream
      for(unsigned int i = 0; i < histogram.size(); i++)
	      ostr << i << " " << histogram[i] << endl;
      ostr << endl;  
      return true;
}
