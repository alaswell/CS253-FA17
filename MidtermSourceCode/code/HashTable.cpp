#include <HashTable.h>

HashTable::HashTable(const HashTable& src) : size(src.size), factor(src.factor), counter(src.counter)
{
	std::cout << "Hash(const Hash& src) Constructor::" << std::endl;
  table = new string[size];
  for(unsigned int index = 0; index < size; index++) {
    table[index] = src.table[index];
  }
}

HashTable::~HashTable()
{
  delete [] table;
  table = 0;
  size = 0;
  std::cout << "Hash Desctructor" << std::endl;
}

HashTable& HashTable::operator = (const HashTable& src)
{
	std::cout << "Hash operator=()" << size << std::endl;
  table = new string[size];
  std::cout << size << std::endl;
  for(unsigned int index = 0; index < size; index++) {
    table[index] = src.table[index];
  }
  size = src.size;
  factor = src.factor;
  return *this;
}

unsigned int HashTable::Resize(unsigned int new_size)
{
	std::cout << "Hash Resize()" << std::endl;
  string* temp = table;
  table = new string[new_size];
  /* ERROR: 
   * loop until index < new_size 
   * results in copying garbage 
   * over from temp[index] 
  */
  for(unsigned int index = 0; index < new_size; index++) {
	  std::cout << "              for" << std::endl;
    table[index] = temp[index];
  }
  std::cout << "made it" << std::endl;
  delete [] temp;
  size = new_size;
  return size;
}

int HashTable::Hash(const string& str) const
{
	std::cout << "Hash Hash()" << std::endl;
  int code = 1;
  for(unsigned int index = 0; index < str.length(); index++) {
    code *= CharCode(str.at(index));
  }
  return code % size;
}

bool HashTable::Contains(const string& str)
{
	std::cout << "Hash Contains()" << std::endl;
  int index = Hash(str);
  return (0 == str.compare(table[index]));
}

bool HashTable::Add(const string& str)
{
	std::cout << "Hash Add()" << std::endl;
  int index = Hash(str);
  if (table[index].empty()) {
    table[index] = str;
    counter++;
    return false;
  }
  else if (0 == str.compare(table[index])) {
    return false;
  }
  else {
    Resize(size * factor);
    Add(str);
    return true;
  }
}
