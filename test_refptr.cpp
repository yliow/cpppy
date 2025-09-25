#include <iostream>

int main()
{
  int * i = new int;
  int * & j = i;
  std::cout << i << std::endl;
  std::cout << j << std::endl;

  *i = 42;
  std::cout << *i << ',' << *j << std::endl;
}
