#include <iostream>
#include <vector>

class Cbaseclass
{

public:
     Cbaseclass() = default;
     Cbaseclass(int x, int y) { std::cout << "base class construtor get called"; }
};

int main()
{
     std::vector<Cbaseclass> a(100); // Declare a vector 'a' that can hold 100 instances of "Cbaseclass" class
     // Loop through each element and initialize it with whatever values you want
     std::cout << "\nreached here line 15" << std::endl;
     for (int i = 0; i < 100; i++)
     {
          a[i] = {1, 2};
     }

     return 0;
}
