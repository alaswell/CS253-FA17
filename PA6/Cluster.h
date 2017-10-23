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
#include<math.h>	/* log10 */
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
	inline const map<string, double>& GetMap() const {return key_value_pair;}
	inline unordered_map<string, string>& GetExceptions() {return exceptions;}

	/* Mutators */
	inline vector<Histogram>& GetCluster() {return cluster;}
	inline map<string, double>& GetMap() {return key_value_pair;}
	map<string, double> GetInverseDocumentFrequencies(vector<Histogram>& cluster, map<string, double>& map);
	bool Read(ifstream& infile, unordered_map<string, string>& map);
	inline void add(Histogram& h) {cluster.push_back(h);}
	
	friend std::ostream& operator<< (std::ostream &out, const Cluster &Cluster);
private:
	vector<Histogram> cluster;			/// a vector of histograms
	map<string, double> key_value_pair;		/// a map w/the number of times a str appears in all Histograms
	unordered_map<string, string> exceptions;	/// exception table for porter alogrithm
};

#endif // CLUSTER_H_INCLUDE
