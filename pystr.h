//=============================================================================
// pystr
//=============================================================================

#ifndef PYSTR_H
#define PYSTR_H

#include <iostream>
#include <string>
#include "pyobject.h"
#include "pytype.h"

extern pytype pystrtype;

class pystr_exception
{};

inline std::string char_to_string(char c)
{
  std::string s(" ");
  s[0] = c;
  return s;
}


class pystr : public pyobject
{
public:
  pystr(const std::string & s="") : _x(s) {}
  pystr(char c) : _x(char_to_string(c)) {}
    pystr(char s[]) : _x(s) {}

  std::string __repr__() const { return _x; }
  pystr operator[](int i) { return pystr((*this)[i]); }
  pytype & type() { return pystrtype; }
  
private:
  std::string _x; // to make this uniform with pynumeric?
  //static pytype & _type;
};


#endif
