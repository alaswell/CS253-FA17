#include <Porter.h>

/*! \file Porter.cpp: implements the Porter class */

/// Evaluation operator.
/// Takes a Histogram and applies an 8-step algorithm to the strings 
/// within the .histogram in order to stem them before counting
void Porter::Eval (Histogram& Hist) const {
	vector<Lexeme>& histogram = Hist.GetHist();
	unsigned int size = histogram.size();

	for(unsigned int i = 0; i < size; i++) {
		Lexeme& lexeme = histogram[i];
		// for each Lexeme
		if(!lexeme.isPunctuation() && !lexeme.isCapital() && !lexeme.hasUpper() && !lexeme.hasDigit()) {
			string& str = lexeme.getString();
			const unsigned int sz = str.size();
			if(sz > 3)
				GoGoPorterNumeroDos(str, sz);
		}
	}
}

/// Execute Porter Algorithm #2
/// Takes a string and its size 
/// iterates through Porter#2 to 
/// systematically stem away the suffix
void Porter::GoGoPorterNumeroDos(string& str, const unsigned int size) const {
	StemUno(str, size);
		std::cout << "1" << std::endl; // DBUG
	StemDos(str, size);
		std::cout << "2" << std::endl; // DBUG
	StemTres(str, size);
		std::cout << "3" << std::endl; // DBUG
	StemCuatro(str, size);
		std::cout << "4" << std::endl; // DBUG
	StemCinco(str, size);
		std::cout << "5" << std::endl; // DBUG
	StemSeis(str, size);
		std::cout << "6" << std::endl; // DBUG
	StemSiete(str, size);
		std::cout << "7" << std::endl; // DBUG
	StemOcho(str, size);
		std::cout << "8" << std::endl; // DBUG
}

/// getRegion(str)
/// Takes a string and returns the defined "Region1"
string Porter::getRegion(const string& str, const unsigned int size) const {
	// IF Region1 exists, it is the substring that; 
	// follows the first consonant (non-vowel) 
	// 	that follows a vowel
	if((size-1) < 2) return ""; // 2 char strings have no Region1

	for(unsigned int i = 0; i < size-2; i++) {
		// only need to check until we are 2 chars from str.size()
		if(isVowel(str, i) && !isVowel(str, i+1)) {
			// vowel followed by not vowel
			return str.substr(i+2);	// return substring that follows
		}
	}	
	return "";	// no Region1
}


/// isDouble(str)
/// Takes a string 
/// returns true if it is any of
/// {'bb', 'dd', 'ff', 'gg', 'mm', 'nn', 'pp', 'rr', 'tt'}
/// all other strings return false
bool Porter::isDouble(const string& str) const {
	char c = str[0];
	switch(c) 
	{
		case 'b': case 'd': case 'f': case 'g': case 'm': 
		case 'n': case 'p': case 'r': case 't':
			if(c == str[1]) return true;
			else return false;
			break;
		default:
			return false;
	}
}


/// isShort(str)
/// Takes a string
/// returns true if it both
/// 1) its Region1 is empty
/// 2) it ends in a short-syllable
bool Porter::isShort(const string& str, const unsigned int size) const {
	// 1) first check Region1	
	if(getRegion(str, size).compare("") != 0)
		return false;	// Region1 is not empty
	if(isShortSyllable(str, size))
		return true;
	return false; // failed pass tests
}


/// isShortSyllable(str)
/// Takes a string
/// returns true if either
/// 1) it is only 2 chars long 
///	and is a vowel
///	followed by a non-vowel 
/// 2) ends with a non-vowel 
///	followed by a vowel 
///	followed by a non-vowel
///	that is not {'w', 'x', 'y'}
bool Porter::isShortSyllable(const string& str, const unsigned int size) const {
	if(size < 2) return false; // too short to even test

	// 1) check length and pattern
	if(size == 2 && (isVowel(str, 0) && !isVowel(str,1)))
		return true;	

	// 2) check end and pattern
	string ending = str.substr(size-3);
	if(!isVowel(ending, 0) && isVowel(ending, 1) && !isVowel(ending, 2)) {
		switch(ending[2])
		{
			case 'w': case 'x': case 'y':
				return false;
				break;
			default:
				return true;
		}
	}
	return false; // failed tests
}


/// isValidli(str)
/// Takes a string (preceder to an li-ending)
/// returns true if it is any of
/// {'c', 'd', 'e', 'g', 'h', 'k', 'm', 'n', 'r', 't'}
/// all other chars return false;
bool Porter::isValidli(const string& str, const unsigned int size) const {
	char c = str[size-1];
	switch(c)
	{
		case 'c': case 'd': case 'e': case 'g': case 'h':
		case 'k': case 'm': case 'n': case 'r': case 't':
			return true;
			break;
		default:
			return false;
	}
}


/// isVowel(str, int) 
/// Takes a string and a location of a char
/// checks to see if said char is a vowel
/// all other chars return false
bool Porter::isVowel(const string& str, unsigned int loc) const {
	char c = str[loc];
	switch(c) 
	{
		case 'a': case 'e': case 'i': case 'o': case 'u':
			return true;
			break;
		case 'y': 
			// y only counts if it is:
			// NOT the first letter in the word
			// immediately follows a vowel
			if(loc > 0 && (!isVowel(str, loc-1)))
				return true;
			break;
		default:
			return false;
	}
	return false;
}


void Porter::replace(string& str, const string replacement, const int length) const {
	str = str.substr(0, str.size() - length) + replacement;
}

/// StemUno(string) 
/// Step #1 of the Porter Algorithm
/// {"'s'", "'s", "'"} and any one leading "'"
/// Find the longest suffix that matches the ending of the word 
/// If the conditions of the suffix are satisfied, 
/// remove the suffix and add the replacement.
/// If the conditions of the suffix are NOT satisfied,
/// do nothing
void Porter::StemUno(string& str, const unsigned int size) const {
	// first, if the word begins with an apostrophe, remove it
	if(str[0] == '\'')
		str = str.substr(1);

	// find/parse "'s'"
	string suffix = str.substr(size - 3);
	if(!suffix.compare("'s'")) {
		replace(str, "", 3);
		return;
	}
	// find/parse "'s"
	suffix = suffix.substr(1);
	if(!suffix.compare("'s")) {
		replace(str, "", 2);
		return;
	}
	// find/parse "'"
	suffix = suffix.substr(1);
	if(!suffix.compare("'")) {
		replace(str, "", 1);
		return;
	}
	// otherwise, nothing to do here
}


/// StemDos(string) 
/// Step #2 of the Porter Algorithm
/// {"sses", "ies", "ied", "us", "ss", "s"}
/// Find the longest suffix that matches ...
void Porter::StemDos(string& str, const unsigned int size) const {
	int sz = 0;
	string suffix = "";
	
	// sz -> anything over 4 is 5
	if(size > 4) sz = 5;
	else sz = size;
	
	switch(sz)
	{
		// gotta be careful about the size of words here
		// this switch keeps us from trying to parse 
		// a word that is too short
		case 5: 
		case 4:
		// find the longest suffix that matches this step
		suffix = str.substr(size-4);
		if(!suffix.compare("sses")) {
			replace(str, "ss", 4);	// replace with ss
			break;
		}
		// find/parse "ied" || "ies"
		suffix = str.substr(size-3);
		if(!suffix.compare("ied") || !suffix.compare("ies")) {  
			if(size > 4) replace(str, "i", 3);	// replace with i
			else replace(str, "ie", 3);		// replace with ie
			break;
		}
		case 3:
		// find/parse "us" || "ss"
		suffix = str.substr(size-2);
		if(!suffix.compare("us") || !suffix.compare("ss")) 
			break; // replace with same
		case 2:
		// find/parse "s"
		suffix = str.substr(size-1);
		if(!suffix.compare("s")) {
			for(unsigned int i = 0; i < size - 2; i++) {
				if(isVowel(str, i))
					replace(str, "", 1);	// replace with (none)
			}
			break;
		}
		default: break;
	}
	// otherwise, nothing to do here
}


/// StemTres(str, int)
/// Step #3 of the Porter Algorithm
/// Takes a string and its size and parses off:
/// {"eed", "eedly", "ed", "edly", "ing", "ingly"}
/// Find the longest suffix that matches ...
void Porter::StemTres(string& str, const unsigned int size) const {
	string suffix = "";
	unsigned int sz = 0;

	// sz -> anything over 6 is 7
	if(size > 6) sz = 7;
	else sz = size;
	
	switch(sz)
	{
		// same as dos, need to watch for little strings
		case 7:
		// find/parse "eedly"
		// suffix must occur in Region1 which by 
		// definition means size has to be >= 7
			suffix = str.substr(size-5);
			if(!suffix.compare("eedly")) {
				if(getRegion(str, size).find("eedly") != std::string::npos) {
					replace(str, "ee", 5);	// replace with ee
				}
			break;
			}
		case 6:
		// find/parse "ingly"
		// preceder must contain a vowel
		// ie: size >= 6 by definition
			suffix = str.substr(size-5);
			if(!suffix.compare("ingly")) {
				// let the alpha function handle the messy work
				StemTresAlpha(str, getPreceder(str, 5), 5);
				break;
			}
		// find/parse "edly"
		case 5:
			suffix = str.substr(size-4);
			if(!suffix.compare("edly")) {
				// let the alpha function handle the messy work
				StemTresAlpha(str, getPreceder(str, 4), 4);
				break;
			}
		// find/parse "eed"
 			suffix = str.substr(size-3);	
			// again, must occur in Region1 
			// ie: size >= 5 by definition
			if(!suffix.compare("eed")) {
				if(getRegion(str, size).find("eed") != std::string::npos) {
					replace(str, "ee", 3);
				}
				break;
			}
		// find/parse "ing"
		case 4: 
			suffix = str.substr(size-3);
			if(!suffix.compare("ing")) {
				// alpha function to the rescue! 
				StemTresAlpha(str, getPreceder(str, 3), 3);
				break;
			}
		// find/parse "ed"
		case 3:
			suffix = str.substr(size-2);
			if(!suffix.compare("ed")) {
				// go go funciton alpha 
				StemTresAlpha(str, getPreceder(str, 2), 2);
				break;
			}
		default: break;
	}
	// otherwise, nothing to do here
}


/// StemTresAlpha(str, int)
/// Takes a string and a length 
/// this particular case repeats a lot of requiremnts 
/// and it has some aditional special requirements
///  that have to be checked after replacing the suffix
/// This alpha function takes care all of that, rather than
///  copy + pasta everywhere
/// Special Requirements:
/// 	1) if preceder ends in {"at", "bl", "iz"}
/// 	2) if preceder isDouble()
/// 	3) if preceder isShort()
void Porter::StemTresAlpha(string& str, const string& preceder, const unsigned int length) const {
	// length = size of suffix
	// size = size of preceder
	unsigned int size = preceder.size();

	// preceder must contain a vowel
	for(unsigned int i = 0; i < size; i++) {
		if(isVowel(preceder, i)) {
			replace(str, "", length);	// replace suffix with (none)

			if(size > 1) {
				// still need to check 1,2, and 3 and adjust accordingly
				string ending = preceder.substr(size-2);
				if(!ending.compare("at") || !ending.compare("bl") || !ending.compare("iz")) 
					str = str + "e";	// add an e
				else if(isDouble(ending))
					replace(str, "", 1);	// replace last letter with (none)
				else if(isShort(preceder, size))
					str = str + "e";	// add an e
				break;	
			}
		}
	}
}

/// StemCuatro(str, int)
/// Step #4 of the Porter Algorithm
/// Takes a string and its size and parses off:
/// {"y"}
void Porter::StemCuatro(string& str, const unsigned int size) const {
	// size = str.size()
	// sz   = preceder.size()
	
	char suffix = str[size-1];
	if(suffix == 'y') {
		string preceder = getPreceder(str, 1);
		unsigned int sz = preceder.size();
		// y must follow a consonant that is not the first word in str
		// ie: preceder.size() >= 2
		if(sz < 2) return;	
		else {
			preceder = preceder.substr(sz-1);	// get the last char in the preceder
			if(!isVowel(preceder, 0))
				replace(str, "i", 1);	// replace with i
		}
	}	
	// otherwise, nothing to do here
}


/// StemCinco(str, int)
/// Step #5 of the Porter Algorithm
/// Takes a string and its size and parses off:
/// {"ization", "ational", "fulness", "ousness", "iveness", "tional", 
///  "biliti", "lessli", "entli", "ation", "alism", "aliti", "ousli", 
///  "iviti", "fulli", "enci", "anci", "abli", "izer", "ator", "alli",
///  "bli", "ogi", "li"}
///  phew! 
void Porter::StemCinco(string& str, const unsigned int size) const {
	int sz = 0;
	string suffix = "";
	
	// sz -> anything over 6 is 7
	if(size > 6) sz = 7;
	else sz = size;
	

	switch(sz) 
	{
		case 7:
			suffix = str.substr(size-7);
			if(!suffix.compare("ization")) {
				replace(str, "ize", 7);	// replace with ize
				break;
			}
			else if(!suffix.compare("ational")) {
				replace(str, "ate", 7);	// replace with ate
				break;
			}
			else if(!suffix.compare("fulness")) {
				replace(str, "ful", 7);	// replace with ful
				break;
			}
			else if(!suffix.compare("ousness")) {
				replace(str, "ous", 7); // replace with ous
				break;
			}
			else if(!suffix.compare("iveness")) {
				replace(str, "ive", 7); // replace with ive
				break;
			}
		case 6:
			suffix = str.substr(size-6);
			if(!suffix.compare("tional")) {
				replace(str, "tion", 6); // replace with tion
				break;
			}
			else if(!suffix.compare("biliti")) {
				replace(str, "ble", 6);	// replace with ble
				break;
			}
			else if(!suffix.compare("lessli")) {
				replace(str, "less", 6); // replace with less
				break;
			}
		case 5:
			suffix = str.substr(size-5);
			if(!suffix.compare("entli")) {
				replace(str, "ent", 5);	// replace with ent
				break;
			}
			else if(!suffix.compare("ation")) {
				replace(str, "ate", 5);	// replace with ate
				break;
			}
			else if(!suffix.compare("alism")) {
				replace(str, "al", 5);	// replace with al
				break;
			}
			else if(!suffix.compare("aliti")) {
				replace(str, "al", 5);	// replace with al
				break;
			}
			else if(!suffix.compare("ousli")) {
				replace(str, "ous", 5);	// replace with ous
				break;
			}
			else if(!suffix.compare("iviti")) {
				replace(str, "ive", 5);	// replace with ive
				break;
			}
			else if(!suffix.compare("fulli")) {
				replace(str, "ful", 5);	// replace with ful
				break;
			}
		case 4:
			suffix = str.substr(size-4);
			if(!suffix.compare("enci")) {
				replace(str, "ence", 4); // replace with ence
				break;
			}
			else if(!suffix.compare("anci")) {
				replace(str, "ance", 4); // replace with ance
				break;
			}
			else if(!suffix.compare("abli")) {
				replace(str, "able", 4); // replace with able
				break;
			}
			else if(!suffix.compare("izer")) {
				replace(str, "ize", 4); // replace with ize
				break;
			}
			else if(!suffix.compare("ator")) {
				replace(str, "ate", 4); // replace with ate
				break;
			}
			else if(!suffix.compare("alli")) {
				replace(str, "al", 4); // replace with al
				break;
			}
			else { // try "ogi"
				suffix = str.substr(size-3);
				if(!suffix.compare("ogi")) {
					// ogi is special, it must be preceded by 'l'
					// which means it needs a string of size >= 4
					string prev = str.substr(size-4, 1);
					if(!prev.compare("l")) {
						replace(str, "og", 3); // replace with og
					}
					break;
				}
			}
		case 3:
			suffix = str.substr(size-3);
			if(!suffix.compare("bli")) {
				replace(str, "ble", 3); // replace with ble
				break;
			}
			else {
				suffix = str.substr(size-2);
				if(!suffix.compare("li")) {
					// preceder must end in a valid-li char
					string preceder = getPreceder(str,2);
					if(isValidli(preceder, preceder.size())) 
						replace(str, "", 2); // replace with (none)
					break;
				}
			}
		default: break;
	}
	// otherwise, nothing to do here
}


/// StemSeis(str, int)
/// Step #6 of the Porter Algorithm
/// Takes a string and its size and parses off:
/// {"ational", "tional", "alize", "ative", "icate", "iciti", "ical", "ness", "ful"}
void Porter::StemSeis(string& str, const unsigned int size) const {
	// all these require the suffix to be 
	// at the very least in Region1 
	string region1 = getRegion(str, size);
	if(!region1.compare("")) return; // region1 does not exist
	unsigned int sz = 0;	
	string suffix = "";
	
	// sz -> anything over 8 is 9
	if(size > 8) sz = 9;
	else sz = size;
	
	switch(sz) 
	{
		case 9: 
		// region1 requires at least 2 chars to precede the suffix
			suffix = str.substr(size-7);
			if(!suffix.compare("ational")) {
				if(region1.find(suffix) != std::string::npos)
					replace(str, "ate", 7); // replace with ate
				break;
			}
			else {
			// ative requires a region2, so it goes here
				suffix = str.substr(size-5);
				if(!suffix.compare("ative")) {
					string region2 = getRegion(region1, size);
					if(region2.find(suffix) != std::string::npos)
						replace(str, "", 5); // replace with (none)
					break;
				}
			}
		case 8:
			suffix = str.substr(size-6);
			if(!suffix.compare("tional")) {
				if(region1.find(suffix) != std::string::npos)
					replace(str, "tion", 6); // replace with tion
				break;
			}
		case 7:
			suffix = str.substr(size-5);
			if(!suffix.compare("alize")) {
				if(region1.find(suffix) != std::string::npos)
					replace(str, "al", 5); // replace with al
				break;
			}
			else if(!suffix.compare("icate") || !suffix.compare("iciti")) {
				if(region1.find(suffix) != std::string::npos)
					replace(str, "ic", 5); // replace with ic
				break;
			}				
		case 6:
			suffix = str.substr(size-4);
			if(!suffix.compare("ical")) {
				if(region1.find(suffix) != std::string::npos)
					replace(str, "ic", 4); // replace with ic
				break;
			}	
			else if(!suffix.compare("ness")) {
				if(region1.find(suffix) != std::string::npos)
					replace(str, "", 4); // replace with (none)
				break;
			}
		case 5:
			suffix = str.substr(size-3);
			if(!suffix.compare("ful")) {
				if(region1.find(suffix) != std::string::npos)
					replace(str, "", 3); // replace with (none)
			}
			break;
		default: break;
	}
	// otherwise, nothing to do here
}


/// StemSiete(str, int)
/// Step #7 of the Porter Algorithm
/// Takes a string and its size and parses off:
/// {"ement", "ance", "ence", "able", "ible", "ment", "ant", "ent", "ism", 
///  "ate", "iti", "ous", "ive", "ize", "ion", "al", "er", "ic"}
void Porter::StemSiete(string& str, unsigned const int size) const {
	// all these require the suffix to be 
	// be in Region2 
	string region = getRegion(str, size);
	if(!region.compare("") || region.size() < 4) return; // empty region1

	region = getRegion(region, region.size()); // region2
	if(!region.compare("")) return; // region2 does not exist
	
	unsigned int sz = 0;	
	string suffix = "";
	
	// sz -> anything over 8 is 9
	if(size > 8) sz = 9;
	else sz = size;
	
	switch(sz) 
	{
		case 9:
			suffix = str.substr(size-5);
			if(!suffix.compare("ement")) {
				if(region.find(suffix) != std::string::npos) 
					replace(str, "", 5); // replace with (none)
				break;
			}
		case 8:
			suffix = str.substr(size-4);
			if(!suffix.compare("ance")) {
				if(region.find(suffix) != std::string::npos)
					replace(str, "", 4); // replace with (none)
				break;
			}	
			else if(!suffix.compare("ence")) {
				if(region.find(suffix) != std::string::npos)
					replace(str, "", 4); // replace with (none)
				break;
			}
			else if(!suffix.compare("able")) {
				if(region.find(suffix) != std::string::npos)
					replace(str, "", 4); // replace with (none)
				break;
			}
			else if(!suffix.compare("ible")) {
				if(region.find(suffix) != std::string::npos)
					replace(str, "", 4); // replace with (none)
				break;
			}
			else if(!suffix.compare("ment")) {
				if(region.find(suffix) != std::string::npos)
					replace(str, "", 4); // replace with (none)
				break;
			}
		case 7: 
			suffix = str.substr(size-3);
			if(!suffix.compare("ant")) {
				if(region.find(suffix) != std::string::npos)
					replace(str, "", 3); // replace with (none)
				break;
			}	
			else if(!suffix.compare("ent")) {
				if(region.find(suffix) != std::string::npos)
					replace(str, "", 3); // replace with (none)
				break;
			}
			else if(!suffix.compare("ism")) {
				if(region.find(suffix) != std::string::npos)
					replace(str, "", 3); // replace with (none)
				break;
			}
			else if(!suffix.compare("ate")) {
				if(region.find(suffix) != std::string::npos)
					replace(str, "", 3); // replace with (none)
				break;
			}
			else if(!suffix.compare("iti")) {
				if(region.find(suffix) != std::string::npos)
					replace(str, "", 3); // replace with (none)
				break;
			}
			else if(!suffix.compare("ous")) {
				if(region.find(suffix) != std::string::npos)
					replace(str, "", 3); // replace with (none)
				break;
			}
			else if(!suffix.compare("ive")) {
				if(region.find(suffix) != std::string::npos)
					replace(str, "", 3); // replace with (none)
				break;
			}
			else if(!suffix.compare("ize")) {
				if(region.find(suffix) != std::string::npos)
					replace(str, "", 3); // replace with (none)
				break;
			}
			else if(!suffix.compare("ion")) {
				if(region.find(suffix) != std::string::npos) {
					// the preceder must end in "s" or "t"
					string preceder = getPreceder(str, 3);
					preceder = preceder.substr(preceder.size()-1);	// only care about last char
					if(!preceder.compare("s") || !preceder.compare("t"))
						replace(str, "", 3); // replace with (none)
				break;
				}
			}
		case 6:
			suffix = str.substr(size-2);
			if(!suffix.compare("al")) {
				if(region.find(suffix) != std::string::npos)
					replace(str, "", 2); // replace with (none)
				break;
			}
			else if(!suffix.compare("er")) {
				if(region.find(suffix) != std::string::npos)
					replace(str, "", 2); // replace with (none)
				break;
			}
			else if(!suffix.compare("ic")) {
				if(region.find(suffix) != std::string::npos)
					replace(str, "", 2); // replace with (none)
				break;
			}
		default: break;
	}
	// otherwise, nothing to do here
}


/// StemOcho(str, int)
/// Step #8 of the Porter Algorithm
/// Takes a string and its size and parses off:
/// {"e", "l"}
void Porter::StemOcho(string& str, const unsigned int size) const {
	// both of these require at least region1
	// ie: size >= 3
	if(size < 3) return;	// nothing to do here

	string preceder = str.substr(size-2,1);	// only care about the last char

	string region1 = getRegion(str, size);
	if(!region1.compare("")) return; // region1 does not exist

	string region2 = getRegion(region1, size);
	string suffix = str.substr(size-1);


	if(!suffix.compare("e")) {
		if(region2.find(suffix) != std::string::npos) {
			replace(str, "", 1); 	// replace with (none)
		}
		else if(region1.find(suffix) != std::string::npos) {
			// preceder must not end in a short syllable
			if(!isShortSyllable(preceder, preceder.size()))
				replace(str, "", 1); // replace with (none)
		}
		return;
	}
	else if(!suffix.compare("l")) {
		if(region2.find(suffix) != std::string::npos) {
			// preceder must end in "l"
			if(!preceder.compare("l"))
				replace(str, "", 1); // replace with (none)
		}
		return;
	}
	// othewise, nothing to do here
} // END OF PORTER STEMMING
