#include <ColemanLiau.h>

/*! \file ColemanLiau.cpp: implements the Coleman-Liau class */

/// Evaluation operator.
/// Takes a Histogram and applies the Coleman-Liau equation 
/// to comeup with a reading level of the document
double ColemanLiau::Eval(Histogram& Hist) const {
	double l_doc = 0;
	double s_doc = 0;
	double w_doc = 0;
	vector<Lexeme>& histogram = Hist.GetHist();

	for(auto &l : histogram) {
		if(!l.isPunctuation()) {
			// if not a punctuation string
			string& s = l.getString();
			if(s[0] == '+') // ignore the +
				l_doc += l.getString().length() - 1;	// inc l_doc by # of letters
			else 
				l_doc += l.getString().length();	// inc l_doc by # of letters
			w_doc++;	// increment w_doc by one
		}
		else {
			if(l.isPunctuation() == 2) 
				s_doc++;
		}
	}
/*	DBUG
 *	printf("Letters:\t\t\t%f\n", l_doc);	
 *	printf("Words:\t\t\t\t%f\n", w_doc);
 *	printf("Sentences:\t\t\t%f\n", s_doc);
*/
	// L(doc) = 0.0588*[(# of letters/# of words)*100]
	l_doc /= w_doc;
	l_doc *= 100;
	l_doc *= 0.0588;

	// S(doc) = 0.296*[(# of sentences/# of words)*100]
	s_doc /= w_doc;
	s_doc *= 100;
	s_doc *= 0.296;

	return l_doc - s_doc - 15.8;
} // END OF COLEMAN-LIAU


std::ostream& operator<< (std::ostream &out, const ColemanLiau &c0) {
	ColemanLiau cl = c0;
	out << cl.getIndex();
	return out;
}
