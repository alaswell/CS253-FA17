#include <Reader.h>
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;


void hasher(HashTable& ht1) {
	//Reader R1("testing this");
	//Reader R2("testing this");
	ht1.Add("testing");	
	return; 
}

int main(int argc, char** argv)
{
/*	string* str = new string("test string");
	string tmp = *str;
	Reader r2("This is a test");
	Reader r3("This is a test");
	cout << r2.Compare(*str) << endl;
	//Reader r4("A");
	//r4 = r3;
	//Reader* r5 = new Reader("Type");
	//delete r5;
	//const Reader r6("const");	
*/	//HashTable ht1(9999, 12);
	//HashTable* ht2 = new HashTable();
	//HashTable h;
	//hasher(h);
	//cout << "eyp" << endl;
	
	/* 12 allocs, 1 free */
		HashTable* hArr = new HashTable[10];
		HashTable* hptr = hArr + 2;
		delete hArr;
	/* plus the 1:1 from main */
	//std::cout << (*hptr == hArr[2]) << endl;
	cout << (hptr == &hArr[2]) << endl;
//MEMLEAK:	r4 = r3; 
//ERROR:	r1.Resize(9999);
//ERROR:	Reader r1("This sihT");
	return 0;
}
