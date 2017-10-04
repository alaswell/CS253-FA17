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
	Lexeme(string s = "", bool c = 0, int p = 0) : str(s), capital(c), punctuation(p) {}
	
	/* Accessors */
	inline bool isCapital() const { return capital; }
	inline int isPunctuation() const { return punctuation; }
	inline string& getString() { return str; } 

	/* Mutators */
	inline void setCapital(bool cap) { capital = cap; }
	inline void setPunctuation(int punct) { punctuation = punct; }
	inline void setString(string s) { str = s; }

private: 
	string str;
	bool capital; 
	int punctuation;
};

#endif // LEXEME_H_INCLUDE
