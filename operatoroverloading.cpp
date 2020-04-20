#include <iostream>

class Vector
{
public:
     int a;
     int b;
     int c;
     int *d;
     Vector() = default;
     Vector(int a, int b, int c, int d) : a(a), b(b), c(c)
     {
          std::cout << "paramertised constructor get called " << std::endl;
          this->d = new int;
          std::cout << "d " << this->d << std::endl;
          *(this->d) = d;
     }
     Vector operator+(const Vector &src)
     {
          std::cout << "Plus + Opertor got called" << std::endl;
          return Vector(a + src.a, b + src.b, c + src.c, *d + *src.d);
     }

     Vector operator=(const Vector &&src)
     {
          std::cout << "Assignment Opertor got called" << std::endl;

          // a = src.a;
          // b = src.b;
          // c = src.c;
          // d = new int;
          // *d = *src.d;
     }
     Vector(const Vector &src)
     {
          std::cout << "copy constructor called" << std::endl;
          a = src.a;
          b = src.b;
          c = src.c;
          d = src.d;
          // d = new int;
          // *d = *src.d;
     }
};

void Print(const Vector &obj)
{
     std::cout << "\nA value is " << obj.a
               << "\n B value is " << obj.b
               << "\n C Value is " << obj.c
               << "\n D Address is " << obj.d
               << "\n D value is " << *obj.d;
}
int main()
{
     Vector v1(1, 1, 1, 1);
     Vector v3(2, 2, 2, 2);
     Vector v2 = v1;
     Vector v4 = v3;
     // Vector v3;
     // v3 = v2 + v1;
     // v2 = v1;

     Print(v1);
     Print(v2);
     Print(v3);
     Print(v4);
     // Print(v3);
}
