#include "Cluster.h"

/*! \file Cluster.cpp: implements the Cluster class */

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
	const vector<Histogram>& c0 = Cluster.GetCluster();
	for(auto &h : c0) {
		auto m = h.GetMap();
		h.Write(std::cout, m);
	}		
	return out;
}
