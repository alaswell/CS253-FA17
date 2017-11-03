#include <ColemanLiau.h>

/*! \file ColemanLiau.cpp: implements the Coleman-Liau class */

/// Evaluation operator.
/// Takes a Histogram and applies the Coleman-Liau equation 
/// to comeup with a reading level of the document
void ColemanLiau::Eval(Histogram& Hist) const {
	double l_doc = 0;
	double s_doc = 0;
	vector<Lexeme>& histogram = Hist.GetHist();

	for(auto &l : histogram) {
		if(!l.isPunctuation()) {
			l_doc += l.getString().length();
		}
		else {
			if(l.isPunctuation() == 2) 
				s_doc++;
		}
	}
	// L(doc) = 0.0588*[(# of letters/# of words)*100]
		printf("L(doc) %f\n", l_doc);	// DBUG
	l_doc /= histogram.size();
		printf("L(doc) %f\n", l_doc);	// DBUG
	l_doc *= 100;
		printf("L(doc) %f\n", l_doc);	// DBUG
	l_doc *= 0.0588;
		printf("L(doc) %f\n", l_doc);	// DBUG

		printf("S(doc) %f\n", s_doc);	// DBUG
} // END OF COLEMAN-LIAU
