//=============================================================================
// pyobject and p_pyobject
//=============================================================================

#ifndef PYOBJECT_H
#define PYOBJECT_H

#include "_pyobject.h"
#include "pytype.h"

class p_pyobject;
class pyobject;

class pyobject: public _pyobject
{
 public:
  virtual pytype & type() { return *_type; }
  virtual pyobject & operator=(const pyobject &) {}
 private:
  static pytype * _type;
};

inline pytype & type(pyobject & p) { return p.type(); }

inline
std::string debug(pyobject & p)
{
  char t[100];
  sprintf(t, "%s, id:%d", p.__repr__().c_str(), p.id());
  return std::string(t);
}

//=============================================================================
// p_pyobject
//=============================================================================

class p_pyobject
{
  p_pyobject(pyobject & p) : _p(&p) {}
    pyobject & deref() { return *_p; }
  pyobject * _p;
};


virtual p_pyobject pyobject::get_pointer() { return p_pyobject(this); }

#endif
