#include <iostream>

class D;
class C{
 public:
  C& operator=(C);
};

class D
{
public:
  D(int i) {}
  operator C() { return C(); }
};

//inline
C& C::operator=(C c)
{
  std::cout << "C::=\n";
  return *this;
}

int main()
{
  C c;
  c = 1;
}
