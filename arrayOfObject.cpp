#include <iostream>
#include <vector>

class Cbaseclass
{
public:
     static int i;
     Cbaseclass() { ++i; };
     Cbaseclass(int x, int y) { ++i; }
};

int Cbaseclass::i = 0;

int main()
{
     std::vector<Cbaseclass> a;
     a.reserve(100);
     for (size_t i = 0; i < 100; ++i)
     {
          a.emplace_back(1, 0); // give it arguments of type needed for construction
     }
     std::cout << "i value " << Cbaseclass::i << std::endl;
     return 0;
}