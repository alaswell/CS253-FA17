#include <HashTable.h>
#include <Reader.h>
#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char** argv)
{
	switch(argv[1][0]) {
		case 'a' : {
				   Reader r("foo bar foo bar foo bar ");
				   cout << r.Compare(" foo bar toaster") << endl;
				   cout << r.Count() << endl;
				   cout << r.Size() << endl;
				   return 0;
			   }
		case 'b' : {
				   HashTable ht1(17, 1);
				   HashTable ht2(1, 2);
				   ht1.Add("foo");
				   ht2 = ht1;
				   cout << ht2.Size() << endl;
				   return 0;
			   }
		case 'g' : {
				   // Be aware that int('a') == 99 and
				   // booleans print as 1 (true) or 0 (false)
				   HashTable ht(99, 1);
				   ht.Add("a");
				   cout << ht.Contains("a") << endl;
				   ht.Add("aa");
				   cout << ht.Contains("a") << endl;
				   cout << ht.Contains("aa") << endl;
				   return 0;
			   }
		case 'd' : {
				   Reader* r1 = new Reader("alpha beta gamma");
				   Reader r2(*r1);
				   r1->Resize(97);
				   cout << r1->Count() << endl;
				   cout << r1->Compare("alpha") << endl;
				   cout << r2.Compare("alpha") << endl;
				   delete &r2;
				   return 0;
			   }
	}
	return -1;
}
