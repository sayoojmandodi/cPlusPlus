#include <iostream>
#include <vector>

class Cbaseclass
{
public:
     int x;
     int *ptr;
     Cbaseclass() { std::cout << "default constr called .."; };
     Cbaseclass(int x) : x(x)
     {
          ptr = new int;
          *ptr = x;
          std::cout << "param const called ..." << std::endl;
     }

     Cbaseclass(Cbaseclass &&obj)
     {
          std::cout << "move const get called" << std::endl;
          x = obj.x;
          this->ptr = obj.ptr;
          obj.ptr = nullptr;
     }

     ~Cbaseclass() { delete ptr; }
};

int main()
{
     std::vector<Cbaseclass> a;
     a.reserve(100);
     for (size_t i = 0; i < 10; ++i)
     {
          a.push_back(Cbaseclass(1)); // give it arguments of type needed for construction
     }

     return 0;
}