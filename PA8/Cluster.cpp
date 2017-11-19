#include "Cluster.h"

/*! \file Cluster.cpp: implements the Cluster class */


/// Comparison 
/// take two Histograms and output their similarity
/// based on the TFIDF equation in the README.md
double Cluster::Compare(const Histogram& a, const Histogram& b, map<string, double>& invDocFreq) const {
	double idf, sum = 0.0;
	const map<string, int>& mapA = a.GetMap();
	const map<string, int>& mapB = b.GetMap();
	for(auto s : mapA) {
		auto it = mapB.find(s.first);
		if(it != mapB.end()) {
			idf = invDocFreq[s.first];
			sum += (s.second*idf) * (it->second * idf);
		}
	}
	return sum;
}


/// GetInverseDocumentFrequencies.
/// Counts all instances of each string within all Histograms
/// and stores them as a key_value_pair in the map
/// returning the IDF of each word as a map<string, double>
map<string, double> Cluster::GetInverseDocumentFrequencies(vector<Histogram>& clust, map<string, double>& map) {
	// To begin; get the frequency of each word to # of files
	for(auto &h : clust) {
		auto kvp =  h.GetMap();
		for(auto s : kvp) {
			++map[s.first];
		}
	}
	// N = number of Histograms
	int N = clust.size();
	// Have to create a newMap to modify these values to
	// idf(word) = log10(N/freq)
	std::map<string, double> invDocFreq;
	for(std::map<string, double>::iterator it=map.begin(); it != map.end(); it++) {
		invDocFreq[it->first] = log10(N/it->second);
	}
	return invDocFreq;
}


bool Cluster::Read (ifstream& infile, unordered_map<string, string>& map) {
	if(infile.fail()) return false; // input file did not open correctly

        string line;                    // var for holding each line in file
        string word;                    // var for holding each word
        string stem;                    // the associated stem for ^

        // store each string and its associated stem
        while(std::getline(infile, line)) {
                // only parse if the line contains something
                if(line.compare("")) {
                        std::istringstream iss(line);
                        if(!(iss >> word >> stem)) {
                                // incorrect input
                                cerr << "Error Cluster.Read() istringstream : Invalid line read" << endl;
                                return false; 
                        }   
                        // add to the map
                        map.insert({word, stem});
    
                        // if not at eof, the value was not a valid string
                        if(iss.eof() != 1) {
                                string temp;
                                iss >> temp;
                                if(temp.compare("")) {
                                        cerr << "Error Cluster.Read() : File contents are invalid => not a valid string." << endl;
                                        cerr << line << " : " << word << " : " << stem << endl;
                                        return false;
                                }   
                        }   
                }   
    
        }   
    
        // if not at eof, the value was not a valid string
        if(infile.eof() != 1) {
                cerr << "Error Cluster.Read() : File contents are invalid." << endl;
                return false;
        }   
        return true;
}

/// operator<< 
/// outputs the ColemanLiau matrix
/// for the cluster of histograms included therein
std::ostream& operator<< (std::ostream &out, const Cluster &c0) {
	// output to ostream
/*	EACH HISTOGRAM ALL WORDS
	const vector<Histogram>& c0 = Cluster.GetCluster();
	for(auto &h : c0) {
		auto m = h.GetMap();
		h.Write(std::cout, m);
	}		
//
	const map<string, double>& kvp = Cluster.GetMap();
	for(auto s : kvp) out << s.first << " " << s.second << "\n";
*/
	Cluster c1 =  c0;
	unsigned int sz = c1.Size();
	const vector<Histogram>& cl0 = c1.GetCluster();
	map<string, double>& idf = c1.GetMap();
	for(auto h : cl0) {
		for(unsigned int i = 0; i < sz; i++) {
			out << c1.Compare(h, cl0[i], idf) << "\t";
		}
	}
	return out;
}
