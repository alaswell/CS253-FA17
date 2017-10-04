#include <Porter.h>

/*! \file Porter.cpp: implements the Porter class */

/// Evaluation operator.
/// Takes a Histogram and applies an 8-step algorithm to the strings 
/// within the .histogram in order to stem them before counting
void Porter::Eval (Histogram& Hist) const {
	for(auto &l : Hist.GetHist()) {
		auto s = l.getString();
		// for each string in Hist.Histogram
		if(isValid(s)) {
			// need to stem
			Stem1(s);
			Stem2(s);
		}
	}
}

/// isValid(string) 
/// Takes a string and checks to make sure it is valid
/// to preform the Porter Algorithm #2 
bool Porter::isValid(const string& str) const {
	unsigned int len = str.length();

	/* PA4 EXEMPTIONS */
	
	// words with < 3 chars
	if( len <= 2 )
		return false;

	// words with punctuation and capital words
	if(ispunct(str[0])) {
		if(isupper(str[1])) 
			return false;

		bool punctstr = true;
		for(unsigned int i = 1; i < len; i++) 
			if(!ispunct(str[i])) punctstr = false;
		
		if(punctstr) return false;
	}
	
	// one or more capitals or digits
	for(auto c : str) 
		if( isupper(c) || isdigit(c) )
			return false;
	return true;	
}

/// isVowel(char) 
/// Takes a character and check to see if it is vowel
/// all other chars return false
bool Porter::isVowel(const char& c) const {
	switch(c) 
	{
		case 'a': case 'e' : case 'i' : case 'o' : case 'u' :
			return true;
			break;
		default:
			return false;
	}
}

/// Stem#(string) 
/// For each step;
/// find the longest suffix that matches the ending of the word 
/// If the conditions of the suffix are satisfied, 
/// remove the suffix and add the replacement.
/// If the conditions of the suffix are NOT satisfied,
/// do nothing
void Porter::Stem1(string& str) const {
	// Step #1 - 's' | 's | '

	// if the word begins with an apostrophe, remove it
	if(str[0] == '\'')
		str = str.substr(1);
	
	std::size_t pos = str.find("'"); 		// position of apostrophe
	if(pos==std::string::npos) return;

	string compstr = str.substr(pos);	// get a substr from ' to end
	if(compstr.compare("'s'") || compstr.compare("'s") || compstr.compare("'")) {
		str = str.substr(0, pos);	// trim it out
	}
}


void Porter::Stem2(string& str) const {
	// Step #2 - sses | ied | ies | us | ss | s
	int len = str.length();

	size_t pos = str.find_last_of("sses");
	if(pos==std::string::npos) 
		pos = str.find_last_of("ied");
	if(pos==std::string::npos) 
		pos = str.find_last_of("ies");
	if(pos==std::string::npos) 
		pos = str.find_last_of("us");
	if(pos==std::string::npos) 
		pos = str.find_last_of("ss");
	if(pos==std::string::npos) 
		pos = str.find_last_of("s");
	if(pos==std::string::npos || pos == (unsigned int) len ) return;	// none exist in str
	
	
	string compstr = str.substr(pos);
	if(compstr.compare("sses"))
		str = str.substr(0, pos) + "ss";	// replace w/ ""
	else if(compstr.compare("ied") || compstr.compare("ies")) {
		if(len > 4) str = str.substr(0, pos) + "i";	// replace w/ "i"
		else str = str.substr(0, pos) + "ie";	// replace w/ "ie"
	}
	else if(compstr.compare("us") || compstr.compare("ss")) {
		str = str.substr(0, pos) + "us";	// replace w/ "us"
	}
	else if(compstr.compare("s")) {
		if(isVowel(str[pos-1])) return;
		for(auto c : str) {
			if(isVowel(c)) {
				str = str.substr(0, pos);
				std::cout << str << std::endl;
				return;
			}
		}
	}
}
