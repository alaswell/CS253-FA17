#ifndef QUAGGA_DEFINED
#define QUAGGA_DEFINED
#include <iostream>
#include <string>
using std::string;
#include <ZooProperty.h>

class Animal {
public:
  Animal() {animal_ctr++; PrintIf("Animal Constructor");}
  ~Animal() {animal_ctr--; PrintIf("Animal Destructor");}
  inline string Behave() {return WarmUp();}
  virtual void Eat() = 0;
  string WarmUp() {return "Animal::WarmUp \"???\"";}
  void PrintIf(const string& str) {if (debug_flag) std::cout << str << std::endl;}
  void SetDebug(bool flag) {debug_flag = flag;}
protected:
  static int animal_ctr;
  static bool debug_flag;
};

class Mammal : public Animal {
public:
  Mammal() {mammal_ctr += animal_ctr; PrintIf("Mammal Constructor");}
  ~Mammal() {mammal_ctr -= animal_ctr; PrintIf("Mammal Destructor");}
  virtual string WarmUp() {return "Mammal::WarmUp \"Shiver\"";}

protected:
  int body_temperature;
  static int mammal_ctr;
};

class Equine : public Mammal {
public:
 Equine() : equine_ctr(1) {PrintIf("Equine Constructor");}
  ~Equine() {PrintIf("Equine Destructor");}
  Equine(int ctr) : equine_ctr(ctr) {PrintIf("Equine Constructor int DBUG\n\tCtr = " +  equine_ctr);}
 void Eat() {std::cout << "Equine::Eat \"Grass\"";}
protected:
  int equine_ctr;
};

class Quagga : public Equine, public ZooProperty {
public:
 Quagga(int x) : Equine(2^x), ZooProperty(1000), ctr(x) {PrintIf("Quagga Constructor");}
  ~Quagga() {PrintIf("Quagga Destructor");}
  int CtrSum() {return ctr + equine_ctr + mammal_ctr + animal_ctr;}
  virtual string WarmUp() {return "Quagga::WarmUp \"Buck\"";}
protected:
  int ctr;
  bool debug_flag;
};

#endif // QUAGGA_DEFINED
