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


/// Input operator for Exceptions file
/// Format is string ... string\n (repeat)
/// where all strings are delineated by whitespace
/// any other format causes the input stream to fail.
bool Histogram::ReadExceptionTable(ifstream& infile, unordered_map<string, string>& map) {
	if(infile.fail()) return false;	// input file did not open correctly

	bool empty = true;		// the map starts out empty
	string line; 			// var for holding each line in file
	string word; 			// var for holding each word
	string stem;			// the associated stem for ^

	// store each string and its associated stem
	while(std::getline(infile, line)) {
		empty = false;		// there is at least one string in the file

		// only parse if the line contains something
		if(line.compare("")) {
			std::istringstream iss(line);
			if(!(iss >> word >> stem)) {
				// incorrect input
				cerr << "Error Histogram.ReadExceptionFile() istringstream : Invalid line read" << endl;
				return false; 
			}
			// add to the map
			map.insert({word, stem});
	
			// if not at eof, the value was not a valid string
			if(iss.eof() != 1) {
				string temp;
				iss >> temp;
				if(temp.compare("")) {
					cerr << "Error Histogram.ReadExceptionFile() : File contents are invalid => not a valid string." << endl;
					cerr << line << " : " << word << " : " << stem << endl;
					return false;
				}
			}
		}
		
	}
	
	// if not at eof, the value was not a valid string
	if(infile.eof() != 1) {
		cerr << "Error Histogram.Read() : File contents are invalid." << endl;
		return false;
	}

	// if the file was empty we should error
	if(empty) { 
		cerr << "Error Histogram.Read() : Empty file" << endl;
		return false;
	}
	return true;
}


/// Input operator. Format is string string ... str,
/// where all strings are delineated by whitespace.
/// Any other format causes the input stream to fail.
bool Histogram::Read (istream& istr, vector<Lexeme>& hist) 
{
	string word;			// temp var for holding the word
	bool empty = true;		// the vector starts out empty 
	bool punctADD = false;		// flag for added inside loop
	bool punctFnd = false;		// flag for if punctuation was found
	bool digitFnd = false;		// flag for if a digit is found
	bool upperFnd = false;		// flag for if an uppercase char is found
	bool capitalFnd = false;	// flag for if the str is capitalized

	if(istr.fail()) return false;	// input file did not open correctly

	// store all the words in the file in a single vector
	while(istr >> word) {
		empty = false;		// there is at least one string in the file
		punctADD = false;	// reset the flags
		punctFnd = false;	
		digitFnd = false; 
		upperFnd = false;
		capitalFnd = false;

		for(unsigned int i = 0; i < word.length(); i++) {
			// for every char in word check if it:
			// is punctuation
			// has digits
			char ch = word.at(i);
			if(ispunct(ch)) {
				// punctuation found
				// CHECK FOR EXCEPTIONS 

				if(!isException(word, i)) {	
					punctFnd = true;
					if(i > 0) {
						// there is a preceeding string
						hist.push_back(Lexeme(word.substr(0,i), capitalFnd, 0, digitFnd, upperFnd));
						digitFnd = false;	// reset flags
						upperFnd = false;
						capitalFnd = false;
						word = word.substr(i);				//cut out the added string
					}
					// word[0].ispunct() = true
					if(word.length() == 1) 	{
						// it's a single string containing a punctuation char
						// can just add it to histogram
						if(word[0] == '.' || word[0] == '?' || word[0] == '!')
							hist.push_back(Lexeme(word, 0, 2));
						else hist.push_back(Lexeme(word, 0, 1));
						punctADD = true;
						break;
					}
					else 
						word = Histogram::parsePunctuation(word, this->GetHist());	
				}	
			}
			else if(isdigit(ch)) {
				digitFnd = true;
			}
			else if(isupper(ch)) {
				if(i == 0) capitalFnd = true;
				else upperFnd = true;
			}
			// keep checking char's in this word
			if(punctADD) break;	// break out because it was a single str and was added
			if(punctFnd) {
			       	i = 0; // ispunct(word.at(0)) == false
				punctFnd = false;	// reset flags
				upperFnd = false;
				if(word.length() > 0 && !(isdigit(word.at(i)))) digitFnd = false;	
				else digitFnd = true;
				if(word.length() > 0 && !(isupper(word.at(i)))) capitalFnd = false;
				else capitalFnd = true;
			}
		}
		// we have checked each char in this word 
		// for(char c : word) ispunct(c) = false
		if(!punctADD && word.length() > 0) {
			hist.push_back(Lexeme(word, capitalFnd, 0, digitFnd, upperFnd));
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

  	return true;	// eof Histogram::Read() 
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
string Histogram::parsePunctuation(string word, vector<Lexeme>& hist) {
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
	hist.push_back(Lexeme(word.substr(0, strlen), 0, punct));	// ...?!Oops! adds "...?!" to hist
	word = word.substr(strlen);	// ...?!Oops! => Oops!
	return word;
}


void Histogram::findCapitals(vector<Lexeme>& hist){
	for(unsigned int i = 0; i < hist.size(); i++) {
		// for each lexeme in histogram
		Lexeme& lexeme = hist.at(i);

		// first word is special
		if(i == 0) {
			if(lexeme.isCapital() && (!(lexeme.hasUpper() || lexeme.hasDigit()))) {
 				// the word is capitalized, is not an acronym, & doesn't have a digit
				lexeme.setString("+" + lexeme.getString());
				lexeme.setAmbiguous(true);
			}
		}
		else {
			if(lexeme.isCapital()) {
				// need the previous Lexeme
				Lexeme prev = histogram.at(i-1);
				if(prev.isPunctuation() == 2 && (!(lexeme.hasUpper() || lexeme.hasDigit()))) {
 					// prev lexeme contains a '.', '!', or '?'
					// curr lexeme does not contain another upper or digit
					lexeme.setString("+" + lexeme.getString());
					lexeme.setAmbiguous(true);
				}
			}
			// not a capital - do nothing
		}	
	}
}		
	
			
/// Is this string supposed to be a capital or not
/// this method will check to see if we find 
/// any other instance of the ambiguous word
/// in the rest of the document
/// if so ? leave capital : make it lowercase
void Histogram::resolveAmbiguity(vector<Lexeme>& hist) {
	unsigned int size = hist.size();
	bool found = false;
	for(unsigned int i = 0; i < size; i++) {
		// for each lexeme in hist
		if(hist[i].isAmbiguous()) {
			found = false;		// reset the flag
			string& str = hist[i].getString();	// get the string
			str = str.substr(1);	// remove the '+

			// if the lexeme is ambiguous
			// check to see if it should 
			// stay upper or not
			for(unsigned int j = 0; j < size; j++) {
				// other string has to be capital to be eq
				// but also not also ambiguous or an acronym
				if(hist[j].isCapital() && (!(hist[j].isAmbiguous() || hist[j].hasUpper() || hist[j].hasDigit()))) {
					// now grab both strings
					string& other = hist[j].getString();
					if(!str.compare(other)) {
						// found another equal non-ambiguous string
						// do nothing (leave it uppercase)
						found = true;
						hist[i].setAmbiguous(false);
						break;
					}
				}
			}
			if(!found) {
				str[0] = tolower(str[0]);
				hist[i].setCapital(false);
				hist[i].setAmbiguous(false);
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
