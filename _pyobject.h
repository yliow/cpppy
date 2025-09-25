//=============================================================================
// _pyobject
//=============================================================================

#ifndef _PYOBJECT_H
#define _PYOBJECT_H

#include <string>
#include <iostream>

class _pyobject
{
public:
  _pyobject() {}

  virtual std::string __repr__() const { return "";};
  int id() const { return int(this); }
};


inline
std::ostream & operator<<(std::ostream & c, const _pyobject & x)
{
  return (c << x.__repr__());
}

inline int id(const _pyobject & obj) { return obj.id(); }
inline std::string str(const _pyobject & obj) { return obj.__repr__(); }

inline
std::string debug(_pyobject & p)
{
  char t[100];
  sprintf(t, "<<%s, id:%d>>", p.__repr__().c_str(), p.id());
  return std::string(t);
}



#endif
