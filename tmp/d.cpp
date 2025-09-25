#include <cstring>
#include <iostream>

class C
{
  C & operator=(int i)
  {
    std::cout << "=\n";
  }
};


class pyint
{
}


int main()
{
  C c;
  c = 1;
}
