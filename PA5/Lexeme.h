#ifndef LEXEME_H_INCLUDE
#define LEXEME_H_INCLUDE

/*! \file Lexeme.h: Declares the Lexeme class
 */

#include<string>
using std::string;

/*! \brief An implementation of a lexeme (word)
 *
 * A class for holding a word along with some 
 * key attributes that are needed to compute 
 * the stem and some other things 
 */
class Lexeme {
public:
	/// Constructor
	Lexeme(string s = "", bool c = 0, int p = 0, bool d = 0, bool u = 0, bool a = 0) : str(s), capital(c), punctuation(p), digit(d), upper(u), ambiguous(a) {}
	
	/* Accessors */
	inline bool hasDigit() const { return digit; }
	inline bool hasUpper() const { return upper; }
	inline bool isAmbiguous() const { return ambiguous; }
	inline bool isCapital() const { return capital; }
	inline int isPunctuation() const { return punctuation; }
	inline string& getString() { return str; } 

	/* Mutators */
	inline void setAmbiguous(bool amb) { ambiguous = amb; }
	inline void setCapital(bool cap) { capital = cap; }
	inline void setDigit(bool digi) { digit = digi; }
	inline void setPunctuation(int punct) { punctuation = punct; }
	inline void setString(string s) { str.assign(s); }
	inline void setUpper(bool up) { upper = up; }

private: 
	string str;
	bool capital; 
	int punctuation;
	bool digit;
	bool upper; 
	bool ambiguous;
};

#endif // LEXEME_H_INCLUDE
