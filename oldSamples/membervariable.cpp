#include <iostream>

#define CHECK(x)                                               \
     {                                                         \
          std::cout << "the value of x is " << x << std::endl; \
     }
namespace jaanu
{
class Cbase
{

public:
     int a;
     int b;

     Cbase()
     {
          a = 10;
          b = 10;
          std::cout << "base Default constructor got called" << std::endl;
     }

     virtual void print()
     {
          std::cout << "Print in Base " << std::endl;
     }
};

class Cderived : public Cbase
{

public:
     int a;
     int b;
     int *Cd1ptr;
     Cderived()
     {
          a = 5;
          b = 5;
          Cd1ptr = new int;
          *Cd1ptr = 1;
          std::cout << "D1 default constructor got called" << std::endl;
     }
     void print()
     {
          std::cout << "Print in D1" << std::endl;
     }
};

class Cderived2 : public Cderived
{

public:
     Cderived2()
     {
          Cbase::a = 15;
          Cderived::a = 20;

          Cd1ptr = new int;
          *Cd1ptr = 2;
          *Cderived::Cd1ptr = 3;
          Cderived::Cd1ptr = Cd1ptr;
          a = 1;
          b = 1;
          std::cout << "D2 default constructor got called" << std::endl;
     }
     int a; // Cbase::b = 15;
     int b;
     int *Cd1ptr;

     void print()
     {
          std::cout << "print in D2" << std::endl;
     }
};
} // namespace jaanu

int main()
{

     jaanu::Cderived d1;

     std::cout << d1.a << std::endl;
     std::cout << ":::" << *d1.Cd1ptr << std::endl;

     jaanu::Cderived2 d2;

     d1 = d2;
     d2.print();

     std::cout << d1.a << std::endl;
     std::cout << ":::" << *d1.Cd1ptr << std::endl;

     *d2.Cd1ptr = 5;
     std::cout << "after storing 5" << *d1.Cd1ptr << std::endl;
     std::cout << d2.a << std::endl;
     std::cout << ":::" << d2.Cd1ptr << std::endl;

     int i = 0;
     CHECK(++i);
     // std::cout << CHECK(i);

     jaanu::Cbase *obj1 = new jaanu::Cbase;
     jaanu::Cderived *obj2 = new jaanu::Cderived;

     std::cout << " Derived class a " << obj2->a << std::endl;
     std::cout << " Derived class b " << obj2->b << std::endl;

     obj1 = obj2;
     std::cout << " Derived class a " << obj1->a << std::endl;
     std::cout << " Derived class b " << obj1->b << std::endl;

     return 0;
}