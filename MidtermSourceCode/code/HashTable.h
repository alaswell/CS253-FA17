
#include <string>
using std::string;
#include <iostream>

class HashTable {
public:
  HashTable(unsigned int sz = 99, unsigned int f = 7) 
    : size(sz), factor(f), counter(0) { table = new string[size]; std::cout << "Default Hash Constructor" 	    				<< std::endl; }

  HashTable(const HashTable& src);
  ~HashTable();
  HashTable& operator = (const HashTable& src);
  inline unsigned int Count() const {std::cout << "Hash Count()" << std::endl; return counter;}
  inline unsigned int Size() const {std::cout << "Hash Size()" << std::endl; return size;}
  unsigned int Resize(unsigned int resize);
  inline int CharCode(unsigned char ch) const {std::cout << "Hash CharCode()" << std::endl; 
	  					return 2 + int(ch);}
  int Hash(const string& str) const;
  bool Contains(const string& str);
  bool Add(const string& str);

protected:
  unsigned int size;
  unsigned int factor;
  unsigned int counter;
  string* table;
};

