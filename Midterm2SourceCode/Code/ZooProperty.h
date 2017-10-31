#ifndef ZOO_PROPERY_DEFINED
#define  ZOO_PROPERY_DEFINED

class ID {
public:
 ID() : identifier() {identifier = new int(global_identifier++); 
	std::cout << "ID     Constructor DBUG" << std::endl;}
  ~ID() {delete identifier; identifier = NULL; 
	std::cout << "ID     Destructor DBUG" << std::endl;}
  int Identifier() const {return *identifier;}
protected:
  int* identifier;
  static int global_identifier;
};

class ZooProperty : public ID {
public:
  ZooProperty(const ZooProperty& zp) {std::cout << "ZooProperty Constructor" << std::endl;}
  virtual ~ZooProperty() {std::cout << "ZooProperty Destructor" << std::endl;}
  ZooProperty(int cost) : price(cost) {std::cout << "ZooProperty Constructor int DBUG" << std::endl;}

protected:
  int price;
};

#endif //  ZOO_PROPERY_DEFINED
