#include "Cluster.h"

/*! \file Cluster.cpp: implements the Cluster class */


/// 
/// GetInverseDocumentFrequencies.
/// Counts all instances of each string within all Histograms
/// and stores them as a key_value_pair in the map
/// returning the IDF of each word as a map<string, double>
map<string, double> Cluster::GetInverseDocumentFrequencies(vector<Histogram>& cluster, map<string, double>& map) {
	// To begin; get the frequency of each word to # of files
	for(auto &h : cluster) {
		auto kvp =  h.GetMap();
		for(auto s : kvp) {
			++map[s.first];
		}
	}
	// N = number of Histograms
	int N = cluster.size();
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


std::ostream& operator<< (std::ostream &out, const Cluster &Cluster) {
	// output to ostream
/*	EACH HISTOGRAM ALL WORDS
	const vector<Histogram>& c0 = Cluster.GetCluster();
	for(auto &h : c0) {
		auto m = h.GetMap();
		h.Write(std::cout, m);
	}		
*/
	const map<string, double>& kvp = Cluster.GetMap();
	for(auto s : kvp) out << s.first << " " << s.second << "\n";
	return out;
}
