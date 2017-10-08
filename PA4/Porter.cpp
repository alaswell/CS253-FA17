#include <Porter.h>

/*! \file Porter.cpp: implements the Porter class */

/// Evaluation operator.
/// Takes a Histogram and applies an 8-step algorithm to the strings 
/// within the .histogram in order to stem them before counting
void Porter::Eval (Histogram& Hist) const {
	string test0 = Hist.GetHist().at(0).getString();
	string test1 = Hist.GetHist().at(1).getString();
	string test2 = Hist.GetHist().at(2).getString();
	unsigned int i = 0;
	for(i = 0; i < test0.size(); i++) {
		std::cout << isVowel(test0, i); 
	}
	std::cout << "\n" << test1 << "\n";
	for(i = 0; i < test1.size(); i++) {
		std::cout << isVowel(test1, i);
	}
	for(i = 2; i < 14; i++) {
		auto s = Hist.GetHist().at(i).getString();
		std::cout << s;
		int size = s.size() - 2;
		std::cout << "=" << isDouble(s.substr(size)) << std::endl;
	}
	for(; i < Hist.GetHist().size(); i++) {
		auto s = Hist.GetHist().at(i).getString();
		std::cout << s;
		int size = s.size() - 1;
		std::cout << "+" << isValidli(s.substr(size)) << std::endl;
	}
	string r1 = getRegion("definition");
	string r2 = getRegion(r1);
	std::cout << getRegion("try") << "\n" << r1 << "\n" << r2 << 
		"\n" << getPreceder(r2, 3) << 
		"\n" << getPreceder(r1, 3) << std::endl;

	string sh[] = {"bed", "shed", "shred", "bead", "embed", "beds"};
	for(unsigned int j = 0; j < 6; j++) {
		std::cout << isShort(sh[j]) << std::endl;
	}

 	string a[] = {"test's'", "test's", "test'", "abcd", 
		"busses", "tied", "unified", "unties", "bus", "truss", "cats", 
		"aneedly", "ayeed", "aingly", "ablingly", "abbingly", "bedingly", "eedly", "eing", "eed", "eingly",
		"baby", "aby", "bay"};

	for(i = 0; i < 4; i++) {
		unsigned int size = a[i].size();
		StemUno(a[i], size);
		std::cout << a[i] << std::endl;
	}
	for(; i < 11; i++) {
		unsigned int size = a[i].size();
		StemDos(a[i], size);
		std::cout << a[i] << ", ";
	}
	for(; i < 21; i++) {
		StemTres(a[i], a[i].size());
		std::cout << a[i] << ", ";
	}
	for(; i < 24; i++) {
		StemCuatro(a[i], a[i].size());
		std::cout << a[i] << ", ";
	}
	std::cout << std::endl;	
}


/// getRegion1(str)
/// Takes a string and returns the defined "Region1"
string Porter::getRegion(const string& str) const {
	// IF Region1 exists, it is the substring that; 
	// follows the first consonant (non-vowel) 
	// 	that follows a vowel
	unsigned int size = str.size() - 1;
	if(size < 2) return ""; // 2 char strings have no Region1

	for(unsigned int i = 0; i < size-1; i++) {
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
bool Porter::isShort(const string& str) const {
	// 1) first check Region1	
	if(getRegion(str).compare("") != 0)
		return false;	// Region1 is not empty
	if(isShortSyllable(str))
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
bool Porter::isShortSyllable(const string& str) const {
	unsigned int size = str.size();
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
bool Porter::isValidli(const string& str) const {
	char c = str[str.size() - 1];
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
				if(getRegion(str).find("eedly") != std::string::npos) {
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
				if(getRegion(str).find("eed") != std::string::npos) {
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
		if(isVowel(str, i)) {
			replace(str, "", length);	// replace suffix with (none)

			if(size > 1) {
				// still need to check 1,2, and 3 and adjust accordingly
				string ending = str.substr(size-2);
				if(!ending.compare("at") || !ending.compare("bl") || !ending.compare("iz")) 
					str = str + "e";	// add an e
				else if(isDouble(ending))
					replace(str, "", 1);	// replace last letter with (none)
				else if(isShort(str))
					str = str + "e";	// add an e
				break;	
			}
		}
	}
}

/// StemCuatro(str, int)
/// Step #3 of the Porter Algorithm
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
}
