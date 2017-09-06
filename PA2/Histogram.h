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
#include<string>
using std::string;
#include<map>
using std::map;

/*! \brief An integer histogram for simple counting (currently)
 *
 * A class for counting the instances of strings from a file. 
 * This class currently does nothing more than count totals
 * and output said counts to the console. 
 */
class Histogram {
public:
	/// Constructor
	Histogram() : histogram() {}
	Histogram(vector<string> h) : histogram(h) {}

	/* simple accessors */
	/// Retrieve the totals from the buckets
	//inline int Total(int index) const {return histogram.at(index);}	// .at() checks bounds! 
	inline vector<string>& GetHist() {return histogram;}	
	inline map<string, int>& GetMap() {return key_value_map;}
	bool Write(ostream& ostr, map<string, int>& kvm) const;

	/* Mutators */
	inline void SetTotal(string newValue, const int position) {histogram[position] = newValue;}
	bool Eval(Histogram& Hist);
	bool Read(istream& istr, vector<string>& histogram);

private:

	vector<string> histogram;	/// the strings exaclty as they are read in 
	map<string, int> key_value_map;		/// string_count_map containing number of times said string appears
};

#endif // HISTOGRAM_H_INCLUDE
