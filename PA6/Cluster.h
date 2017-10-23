#ifndef CLUSTER_H_INCLUDE
#define CLUSTER_H_INCLUDE

/*! \file Cluster.h: Declares the Cluster class
 */

#include<iostream>
using std::cerr;
using std::endl;
#include<fstream>
using std::ifstream;
using std::istream;
using std::ostream;
using std::istringstream;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<unordered_map>
using std::unordered_map;
#include"Histogram.h"

/*! \brief A cluster of histograms for comparison
 *
 * A class for comparing instances of histograms
 */
class Cluster {
public:
	/// Constructor
	Cluster() : cluster() {}

	/* simple accessors */
	inline const vector<Histogram>& GetCluster() const {return cluster;}	
	inline unordered_map<string, string>& GetExceptions() {return exceptions;}

	/* Mutators */
	bool Read(ifstream& infile, unordered_map<string, string>& map);
	inline void add(Histogram& h) {cluster.push_back(h);}
	
	friend std::ostream& operator<< (std::ostream &out, const Cluster &Cluster);
private:
	vector<Histogram> cluster;			/// a vector of histograms
	unordered_map<string, string> exceptions;	/// exception table for porter alogrithm
};

#endif // CLUSTER_H_INCLUDE
