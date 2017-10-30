#include "Quagga.h"
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
int ID::global_identifier = 1;
int Animal::animal_ctr = 0;
int Mammal::mammal_ctr = 0;
bool Animal::debug_flag = 1;

int main (int argc, char** argv) {
	// ptr->Thing()
	Quagga q(1);
	cout << q.Identifier() << endl;
	cout << q.Behave() << endl;
	cout << q.WarmUp() << endl;
	cout << q.CtrSum() << endl;
	
}
