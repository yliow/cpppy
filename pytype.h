//=============================================================================
// pytype
// Should == be comparison based on id?
//=============================================================================

#ifndef PYTYPE_H
#define PYTYPE_H

//#include "include.h"
#include "_pyobject.h"

class pytype: public _pyobject
{
public:
  pytype(const std::string & s) : _x(s) {}
  pytype(char s[]) : _x(std::string(s)) {}
  std::string __repr__() const { return std::string("<type \"" + _x + "\">"); }
  bool operator==(const pytype & t) const { return id() == t.id(); }
  bool operator!=(const pytype & t) const { return !(*this == t); }

private:
  std::string _x;
};

inline std::string str(const pytype & x) { return x.__repr__(); }

#endif
