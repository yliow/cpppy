#include <iostream>
#include "pystr.h"

int main()
{
  pystr s("hello");
  std::cout << s << std::endl;
  std::cout << debug(&s) << std::endl;
  return 0;
}
