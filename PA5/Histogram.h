#ifndef HISTOGRAM_H_INCLUDE
#define HISTOGRAM_H_INCLUDE

/*! \file Histogram.h: Declares the Histogram class
 */

#include<iostream>
using std::cerr;
using std::endl;
#include<fstream>
using std::ifstream;
using std::istream;
using std::ostream;
#include<sstream>
#include<vector>
using std::vector;
#include<map>
using std::map;
#include<string>
using std::string;
#include<unordered_map>
using std::unordered_map;
#include<Lexeme.h>

/*! \brief A string histogram for simple counting (currently)
 *
 * A class for counting the instances of strings from a file. 
 * This class currently does nothing more than count totals
 * and output said counts to the console. 
 */
class Histogram {
public:
	/// Constructor
	Histogram() : histogram() {}
	Histogram(vector<Lexeme> h) : histogram(h) {}

	/* simple accessors */
	inline vector<Lexeme>& GetHist() {return histogram;}	
	inline map<string, int>& GetMap() {return key_value_map;}
	inline unordered_map<string, string>& GetExceptions() {return exceptions;}
	bool isException(const string& str, const unsigned int i) const;
	bool Write(ostream& ostr, map<string, int>& kvm) const;

	/* Mutators */
	inline void SetString(const string newValue, const int position) {histogram[position].setString(newValue);}
	void Eval(Histogram& Hist);
	bool Read(istream& istr, vector<Lexeme>& histogram);
	bool ReadExceptionTable(ifstream& infile, unordered_map<string, string>& map);
	string parsePunctuation(string word, vector<Lexeme>& histogram);
	void findCapitals(vector<Lexeme>& histogram);
	void resolveAmbiguity(vector<Lexeme>& histogram);

private:
	vector<Lexeme> histogram;			/// the strings exactly as they are read in 
	map<string, int> key_value_map;			/// string_count_map containing number of times said string appears
	unordered_map<string, string> exceptions; 	/// exception table for porter algorithm
};

#endif // HISTOGRAM_H_INCLUDE
