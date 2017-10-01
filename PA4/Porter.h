#ifndef PORTER_H_INCLUDE
#define PORTER_H_INCLUDE

/*! \file Porter.h: Declares the Porter Algorithm class
 */

#include<Histogram.h>
#include<vector>
using std::vector;
#include<string>
using std::string;
#include <cstddef>
using std::size_t;

/*! \brief An implementation of the Porter Algorithm #2
 *
 * A class for parsing grammatical suffixes
 * given specific conditions and replacements
 */
class Porter {
public:
	/// Constructor
	Porter() {}
	
	/* Accessors */
	bool isValid(const string& str) const;
	bool isVowel(const char& c) const;
	void Stem1(string& str) const;
	void Stem2(string& str) const;

	/* Mutators */
	void Eval(Histogram& Hist) const;
};

#endif // PORTER_H_INCLUDE
