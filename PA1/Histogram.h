#ifndef HISTOGRAM_H_INCLUDE
#define HISTOGRAM_H_INCLUDE

/*! \file Histogram.h: Declares the Histogram class
 */

#include<iostream>
using std::cerr;
using std::endl;
#include<fstream>
using std::istream;
using std::ostream;
#include<vector>
using std::vector;

/*! \brief An integer histogram for simple counting (currently)
 *
 * A class for counting the instances of integer numbers from
 * 1 to 19. This class currently does nothing more than count
 * totals and output said counts to the console. 
 */
class Histogram {
public:
	/// Constructor defaults to an zero filled vector of size() 20 
//	Histogram() : histogram(20, 0) {}
	Histogram(vector<int> h = {20, 0}) : histogram(h) {}

	/* simple accessors */
	/// Retrieve the totals from the buckets
	inline int Total(int index) const {return histogram.at(index);}	// .at() checks bounds! 
	inline vector<int>& GetHist() {return histogram;}	
	bool Write(ostream& ostr, vector<int>& histogram) const;

	/* Mutators */
	inline void SetTotal(const int newValue, const int position) {histogram[position] = newValue;}
	bool Read(istream& istr, vector<int>& histogram);

private:

	vector<int> histogram;	/// the totals of each int 0-19
};

#endif // HISTOGRAM_H_INCLUDE
