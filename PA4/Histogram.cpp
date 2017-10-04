#include <Histogram.h>

/*! \file Histogram.cpp: implements the Histogram class */

/// Evaluation operator.
/// Takes a Histogram and counts all instances of distinct strings
/// within the .histogram and stores them as a key_value_pair in the .map
void Histogram::Eval (Histogram& Hist) {
	/* for each string in histogram 
	 * find it in kvm and increment
	 * if not found, std::map::operator[] will zero-initialize
	 */
	for(auto &l : Hist.histogram) ++Hist.key_value_map[l.getString()];
}

/// Input operator. Format is string string ... str,
/// where all strings are delineated by whitespace.
/// Any other format causes the input stream to fail.
bool Histogram::Read (istream& istr, vector<Lexeme>& histogram) 
{
	string word;			// temp var for holding the word
	bool empty = true;		// the vector starts out empty 
	bool punctADD = false;		// flag for added inside loop
	bool punctFnd = false;		// flag for if punctuation was found

	if(istr.fail()) return false;	// input file did not open correctly

	// store all the words in the file in a single vector
	while(istr >> word) {
		if(empty) empty = false;		// there is at least one string in the file
		if(punctADD) punctADD = false;		// reset this flag
		if(punctFnd) punctFnd = false;		// reset this flag

		for(unsigned int i = 0; i < word.length(); i++) {
			// for every char in word check if it is punctuation
			if(ispunct(word.at(i))) {
				// punctuation found
				// CHECK FOR EXCEPTIONS 

				if(!isException(word, i)) {	
					punctFnd = true;
					if(i > 0) {
						// there is a preceeding string
						histogram.push_back(Lexeme(word.substr(0,i), 0, 0));
						word = word.substr(i);				//cut out the added string
					}
					// word[0].ispunct() = true
					if(word.length() == 1) 	{
						// it's a single string containing a punctuation char
						// can just add it to histogram
						if(word[0] == '.' || word[0] == '?' || word[0] == '!')
							histogram.push_back(Lexeme(word, 0, 2));
						else histogram.push_back(Lexeme(word, 0, 1));
						punctADD = true;
						break;
					}
					else 
						word = Histogram::parsePunctuation(word, this->GetHist());	
				}	
			}
			// keep checking char's in this word
			if(punctADD) break;
			if(punctFnd) {
			       	i = 0; // ispunct(word.at(0)) == false
				punctFnd = false;	// reset flag
			}
		}
		// we have checked each char in this word 
		// for(char c : word) ispunct(c) = false
		if(!punctADD && word.length() > 0) {
			histogram.push_back(Lexeme(word, 0, 0));
		}
	}

	// if not at eof, the value was not a valid string
	if(istr.eof() != 1) {
		cerr << "Error Histogram.Read() : File contents are invalid." << endl;
		return false;
	}

	// if the file was empty we should error
	if(empty) { 
		cerr << "Error Histogram.Read() : Empty file" << endl;
		return false;
	}

  	return true;	// eof 
}

/// Write operator. 
/// Typical output operator. Takes an ostream& and a map<string, int>
/// dumps the key_value_pairs to the ostream provided
/// Erros on an empty map<string, int>
bool Histogram::Write(ostream& ostr, map<string, int>& kvm) const
{
      if (ostr.fail()) return false;	// output did not open correctly

      if(kvm.size() < 1) {
	      cerr << "Error Histogram.Write() : Empty map" << endl;
	      return false;
      }

      // dump the totals to the ostream
      for(auto s : kvm) ostr << s.first << " " << s.second << "\n";
      return true;
}

/// Parse Punctuation.
/// Takes a string and a vector<Lexeme>&
/// searches the str and parses out any punctuation
/// returns a string such that ispunct(str[0]) = FALSE
string Histogram::parsePunctuation(string word, vector<Lexeme>& histogram) {
	// ispunct(word[0]) = true 
	// word.length() > 1 = true
	char c = word[0];
	int punct = 1;
	if(c == '.' || c == '?' || c == '!') punct = 2;

	c = word[1];

	// the word either contains a single char
	unsigned int strlen = 1;
	if(ispunct(c)) {
		// or it contains a string of char's
		while(ispunct(c)) {
			// CHECK FOR EXCEPTIONSi
			if(c == '\'') break;	// apostrophes don't count
			if(c == '.' || c == '?' || c == '!') if(punct != 2) punct = 2;
			strlen++;
			if(strlen == word.length()) break;
			c = word[strlen];
		}
	}

	// PARSE IT
	histogram.push_back(Lexeme(word.substr(0, strlen), 0, punct));	// ...?!Oops! adds "...?!" to hist
	word = word.substr(strlen);	// ...?!Oops! => Oops!
	return word;
}

void Histogram::findCapitals(vector<Lexeme>& histogram){
	for(unsigned int i = 0; i < histogram.size(); i++) {
		// for each string in the vector
		string word = histogram.at(i).getString();
		bool firstWord = false;
		
		// if the word is capitalized
		if(isupper(word[0])) {
			if(i == 0) {
				firstWord = true;
				// first word is special, but still has exceptions
				for(unsigned int j = 1; j < word.length(); j++) { 
					char c = word[j];
					if(isupper(c) || isdigit(c)) { firstWord = false; }
				}
				if(firstWord) {
					word = "+" + word;
					histogram.at(i).setString(word);
					histogram.at(i).setCapital(1);
				}
			}
			else {
				// get the previous word 
				Lexeme prev = histogram.at(i-1);
				if(prev.isPunctuation() == 2) {
					firstWord = true;
					// EXCEPTOIN: 
					// if the word has another upperCase letter or a digit;
					// it's an acronym 
					for(unsigned int j = 1; j < word.length(); j++) { 
						char c = word[j];
						if(isupper(c) || isdigit(c)) { firstWord = false; }
					}
					// IF a word is capatalized, is the first word in a sentence
					// is not an acronym, and does not contain a digit;
					// mark is as ambiguous by prepending a '+' sign
					if(firstWord) {
						word = "+" + word;
						histogram.at(i).setString(word);
						histogram.at(i).setCapital(1);
					}	
				}
			}
		}
	}
}
				
/// Is this character an exception to the punctuation
/// checks the string against the provided exceptoins 
/// to ensure that it is valid
/// int i = the location in the word (to en
bool Histogram::isException(const string& word, const unsigned int i) const {
	char c = word.at(i);

	if(c == '\'') { return true; }	// apostrophes don't count
	else if(c == ',') { 		// numbers don't count
		if(i != 0 && (i+1 != word.length())) {
			if(isdigit(word.at(i-1)) && isdigit(word.at(i+1))) { return true; } // do nothing
			else return false;
		}
		else return false;
	}
	else if(c == '.') {		// periods only count in certain instances
		if(i+1 != word.length()) {
			if(isdigit(word.at(i+1))) {
				if(i == 0 || isdigit(word.at(i-1))) { return true; }
				else return false;
			}
			else return false;
		}
		else return false;
	}		
	else return false; // no exceptions
}
