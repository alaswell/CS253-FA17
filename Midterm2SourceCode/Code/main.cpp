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
	cout << "q.Identifier() " << q.Identifier() << endl;
	cout << "q.Behave() " << q.Behave() << endl;
	cout << "q.WarmUp() " << q.WarmUp() << endl;
	cout << "q.CtrSum() " << q.CtrSum() << endl;

	Quagga* q_ptr = new Quagga(2);	
	cout << "q_ptr->CtrSum() " << q_ptr->CtrSum() << endl;
	cout << "q_ptr->WarmUp() " << q_ptr->WarmUp() << endl;
	q_ptr->Eat();
	Equine* eq_ptr = new Equine();
	cout << "\n-==-==-==-==-==-==-==-==-==-==-" << endl;
	cout << "q_ptr->Identifier() " << q_ptr->Identifier() << endl;
	cout << "eq_ptr->WarmUp() " << eq_ptr->WarmUp() << endl;
	eq_ptr->Eat();
	cout << "\n-==-==-==-==-==-==-==-==-==-==-" << endl;
	cout << "q_ptr->CtrSum() " << q_ptr->CtrSum() << endl;
	Mammal* m_ptr = new Equine();
	cout << "m_ptr->WarmUp() " << m_ptr->WarmUp() << endl;
	cout << "m_ptr->Behave() " << m_ptr->Behave() << endl;
	m_ptr->Eat();
	cout << "\n-==-==-==-==-==-==-==-==-==-==-" << endl;
	Animal* a_ptr = q_ptr;
	cout << "a_ptr->WarmUp() " << a_ptr->WarmUp() << endl;
	cout << "q_ptr->CtrSum() " << q_ptr->CtrSum() << endl;	
	cout << "\n-==-==-==-==-==-==-==-==-==-==-" << endl;

	cout << "Vectors" << endl;
	vector<Equine> herd; 
	vector<ZooProperty> property;
	
	herd.push_back(q);
	property.push_back(q);
	cout << "herd.at(0).WarmUp() " << herd.at(0).WarmUp() << endl;
	herd.at(0).Eat();
	cout << "\nherd.at(0).Eat()" << endl;
	cout << "herd.at(0).Behave() " << herd.at(0).Behave() << endl; 
	/* this would compile but causes a seg fault */
//	cout << dynamic_cast<Quagga*>(&herd[0])->CtrSum() << endl;
	cout << "\n-==-==-==-==-==-==-==-==-==-==-" << endl;

	vector<Equine*> ptr_herd;
	vector<ZooProperty*> ptr_property;
	ptr_herd.push_back(q_ptr);
	unsigned int i = 0;
	for(; i < 10 ; i++ ) 
		ptr_herd.push_back(new Quagga(5));
	ptr_property.push_back(q_ptr);
	cout << "ptr_herd.at(0)->WarmUp() " << ptr_herd.at(0)->WarmUp() << endl;
	herd.at(0).Eat();
	cout << "\nptr_herd.at(0).Eat()" << endl;
	cout << "ptr_herd.at(0).Behave() " << ptr_herd.at(0)->Behave() << endl; 
	cout << "ptr_property[0]->Identifier() " << ptr_property[0]->Identifier() << endl;
	for(i = 0 ; i < 10 ; i++) 	
		cout << "ptr_herd[" << i << "]->CtrSum() " << dynamic_cast<Quagga*>(ptr_herd[i])->CtrSum() << endl;
	/* this works fine though */
	cout << dynamic_cast<Quagga*>(ptr_herd[0])->CtrSum() << endl;
	cout << "\n-==-==-==-==-==-==-==-==-==-==-" << endl;
	

	cout << "\tdelete ep" << endl;
	delete eq_ptr;
	cout << "\tdelete qp" << endl;
	delete q_ptr;
	cout << "\tdelete mp" << endl;
	delete m_ptr;
}
