#include <Quagga.h>
#include <iostream>
#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

int ID::global_identifier = 0;
int Animal::animal_ctr = 0;
int Mammal::mammal_ctr = 0;
bool Animal::debug_flag = false;

int main(int argc, char* argv[]) 
{
	if (argc != 2) return -1;

	switch(argv[1][0]) {
	case 'a' : {
		Quagga q(3);
		{	
			Equine e(1);
			cout << q.CtrSum() << endl;
		}
		cout << q.CtrSum() << endl;
		cout << q.WarmUp() << endl;
		cout << q.Behave() << endl;
		cout << q.Equine::WarmUp() << endl;
		cout << q.Mammal::WarmUp() << endl;
		cout << q.Animal::WarmUp() << endl;
		cout << q.Identifier() << endl;
		return 0;
		}
	case 'b' : {
		Quagga q(1);
		q.SetDebug(true);
		Equine e(q);
		return 0;
	}	
	case 'g' : {
		Quagga* qptr = new Quagga(2);
		qptr->SetDebug(true);
		Equine* eptr = qptr;
		delete eptr;
		return 0;
	}
	case 'd' : { 
		vector<ZooProperty> zoo_vec;
		vector<Animal*> ptr_vec;
		Quagga* qptr = new Quagga(7);
		Mammal* mptr = new Equine();
		ptr_vec.push_back(qptr);
		zoo_vec.push_back(*qptr);
		ptr_vec.push_back(mptr);
		cout << zoo_vec[0].Identifier() << endl;
		Quagga* ptr = dynamic_cast<Quagga*>(&zoo_vec[0]);
		if (ptr) cout << ptr->Identifier() << endl;
		else cout << "ptr is null" << endl;
		Equine* ptr2 = dynamic_cast<Equine*>(ptr_vec[0]);
		if (ptr2) cout << ptr2->WarmUp() << endl;
		else cout << "ptr2 is null" << endl;
		if (qptr == ptr_vec[0])
			cout <<  "pointers equal" << endl;
		else cout << "pointers not equal" << endl;
		if (qptr == &zoo_vec[0])
			cout << "pointers equal" << endl;
		else cout << "pointers not equal" << endl;
		if (mptr == ptr_vec[1])
			cout << "pointers equal" << endl;
		else cout << "pointers not equal" << endl;
		return 0;
	}
	case 'e' : {
		Equine* eptr = new Equine;
		Mammal* mptr = reinterpret_cast<Mammal*>(eptr);
		Quagga* qptr = reinterpret_cast<Quagga*>(eptr);
		if (mptr) cout << mptr->WarmUp() << endl;
		else cout << "mptr is NULL" << endl;
		if (qptr) cout << qptr->WarmUp() << endl;
		else cout << "qptr is NULL" << endl;
	}
	}
	return 0;
}
