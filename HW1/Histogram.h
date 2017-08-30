#ifndef HISTOGRAM_H_INCLUDE
#define HISTOGRAM_H_INCLUDE

/*! \file Histogram.h: Declares the Histogram class
 */

#include<iostream>
#include<fstream>
using std::istream;
using std::ostream;

/*! \brief An integer histogram for simple counting (currently)
 *
 * A class for counting the instances of integer numbers from
 * 1 to 19. This class currently does nothing more than count
 * totals and output said counts to the console. 
 */
class Histogram {
	public:
		/// Constructor defaults all buckets to 0
		Histogram(int initialHist[20] = 0) : histogram(initialHist) {}

		/* simple accessors */
		/// Retrieve the totals from the buckets
		inline int total(const int position) const {return histogram[position];}
		bool Write(ostream& ostr) const;

		/* Mutators */
		inline void SetTotal(const int newValue, const int position) {histogram[position] = newValue;}
		bool Read(istream& istr);

	Private:

		int histogram[20];	/// the totals of each int 1-20
};

#endif // HISTOGRAM_H_INCLUDE
