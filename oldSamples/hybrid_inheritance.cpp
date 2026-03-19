#include <iostream>

class Cbase
{
public:
     size_t a;
     int b;

public:
     virtual void print()
     {
          std::cout << "CBase print called" << std::endl;
     }
};

class CDerived1 : virtual public Cbase
{

public:
     CDerived1()
     {
          std::cout << "Dervived 1" << std::endl;
     }
     virtual void print()
     {
          std::cout << "CDerived1 print called" << std::endl;
     }
     void gethedata()
     {
          std::cout << "get the data called" << std::endl;
     }
     int j;
};

class CDerived2 : virtual public Cbase
{
public:
     int c;
     CDerived2()
     {
          std::cout << " Derived 2 " << std::endl;
     }
     virtual void print()
     {
          std::cout << "CDerived2 print called" << std::endl;
     }
};

class CDerived3 : public CDerived1, public CDerived2
{
public:
     int fz;
     void print()
     {
          std::cout << "CDerived3 print called" << std::endl;
     }
};

int main()
{
     // CDerived2 *C2 = new CDerived2;
     CDerived3 C3; // = new CDerived3;

     C3.print(); // This show error becuase the compiler is ambigous of which function has to be called \
                 C3 is derived from both CD2 and CD1 which is again inherited from CBase so once C3 inherit both\
                 print function in both CD1 and Cd2 get inherited by CD3

     C3.CDerived2::print();
     int a = C3.a;
}

int sdf;