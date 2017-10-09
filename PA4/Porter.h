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
	string getRegion(const string& str) const;
	inline string getPreceder(const string& str, const unsigned long long len) const { return str.substr(0,str.size() - len); }

	bool isDouble(const string& str) const;
	bool isShort(const string& str) const;
	bool isShortSyllable(const string& str) const;
	bool isValidli(const string& str) const;
	bool isVowel(const string& str, unsigned long long loc) const;
	bool isValid(const string& str) const;

	/* Mutators */
	void replace(string& str, const string replacement, const int length) const; 
	void GoGoPorterNumeroDos(string& str, unsigned long long size) const;
	void StemUno(string& str, const unsigned long long size) const;
	void StemDos(string& str, const unsigned long long size) const;
	void StemTres(string& str, const unsigned long long size) const;
	void StemTresAlpha(string& str, const string& preceder, const unsigned long long length) const;
	void StemCuatro(string& str, const unsigned long long size) const;
	void StemCinco(string& str, const unsigned long long size) const;
	void StemSeis(string& str, const unsigned long long size) const;
	void StemSiete(string& str, const unsigned long long size) const;
	void StemOcho(string& str, const unsigned long long size) const;
	void Eval(Histogram& Hist) const;
	void Test(Histogram& Hist) const;
};

#endif // PORTER_H_INCLUDE
