#ifndef COLEMANLIAU_H_INCLUDE
#define COLEMANLIAU_H_INCLUDE

/*! \file ColemanLiau.h: Declares the Coleman-Liau Index Algorithm class
 */

#include <Histogram.h>
#include<vector>
using std::vector;
#include<string>
using std::string;
#include <cstddef>
using std::size_t;

/*! \brief An implementation of the Coleman-Liau index algorithm
 *
 * A class for determining the reading level 
 * of a given histogram (document)
 */
class ColemanLiau {
public:
	/// Constructor
	ColemanLiau() {}
	ColemanLiau(double index) : CLIndex(index) {}

	/* Accessors */
	inline double getIndex() { return CLIndex; }

	/* Mutators */
	bool Eval(Histogram& Hist);
	inline void setIndex(double index) { CLIndex = index; }

	friend std::ostream& operator<< (std::ostream &out, const ColemanLiau &c0);
private:
	double CLIndex;
};

#endif // COLEMANLIAU_H_INCLUDE
