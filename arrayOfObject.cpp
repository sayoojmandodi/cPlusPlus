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

     Cbaseclass(Cbaseclass &&obj) noexcept
     {
          std::cout << "mov get called" << std::endl;
          x = obj.x;
          this->ptr = obj.ptr;
          obj.ptr = nullptr;
     }

     ~Cbaseclass()
     {
          delete ptr;
     }
};

int main()
{
     std::vector<Cbaseclass> a;
     a.reserve(100);
     Cbaseclass c(10);
     Cbaseclass d(std::move(c)); // Since copy constr is not declared we need to explicity mention it should call \
     //                               move constructor or else it will not compile. if we declare a move constructor \
     //                               compiler will not declare a copy constructor by default.

     for (size_t i = 0; i < 10; ++i)
     {
          a.push_back(Cbaseclass(1)); // give it arguments of type needed for construction
     }

     // int *testPtr = new int;
     // delete testPtr;
     // delete testPtr;

     return 0;
}