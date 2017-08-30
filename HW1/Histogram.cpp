#include <Histogram.h>

/*! \file Histogram.cpp: implements the Histogram class */

/// Input operator. Format is int int ... int,
/// where all integers are in the range 0-19.
/// Any other format causes the input stream to fail.
bool Histogram::Read (istream& istr) 
{
	int num;	// temp var for holding the number

	/* while not at end of file,
	 * get the number and increment
	 * the corresponding bucket
	 */
	while(!istr.eof()) {
		  istr >> num;
		  histogram[num]++;
	}
  	return !(istr.fail());	// if istr.fail() returns true; it did fail
}

bool Histogram::Write(ostream& ostr) const
{
      if (ostr.fail()) return false;

      // dump the totals to the ostream
      for(int i = 0; i < histogram.size(); i++)
	      ostr << i << " " << histogram[i];
  
      return true;
}
