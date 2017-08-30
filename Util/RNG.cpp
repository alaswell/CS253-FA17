#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include <fstream>

int main(int argc, char** argv) { 
    srand((unsigned)time(0)); 
    int random_int; 

    std::ofstream outfile("testRNG20k.txt", std::ofstream::out);

    for(int i = 0; i < 20000; i++){ 
        random_int = (rand()%20); 
	outfile << random_int << " "; 
    } 
}
