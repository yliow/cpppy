//=============================================================================
// pylist
//=============================================================================

#ifndef PYLIST_H
#define PYLIST_H

#include <iostream>
#include <string>
#include <vector>

#include "pyobject.h"
#include "pytype.h"
#include "pynumeric.h"
#include "pystr.h"

extern pytype pystrtype;
class ptr;

class pylist: public pyobject
{
public:
  pylist(): x(0) {}
  std::string __repr__() const
  {
    std::string s = "[";
    if (x.size() > 0) 
      {
	for (int i = 0; i < x.size(); i++)
	  {
	    pyobject & obj = *x[i];
	    
	    if (obj.type() == pystrtype) s += "\"";
	    s += str(obj);
	    //s += "<" + debug(obj) + ">";
	    if (obj.type() == pystrtype) s += "\"";
	    if (i != x.size() - 1) s += ", ";
	  }
      }
    return (s += "]");
  }

  void append(pyobject * p) { x.push_back(p); }
  void append(pyobject & p) { append(&p); }
  void append(const std::string & s) { append(new pystr(s)); }
  void append(int i) { append(new pyint(i)); }
  void append(double d) { append(new pyfloat(d)); }

  void del(int i)
  {
    if (i >= x.size()) return; // check exception use case
    pyobject & p = *x[i];
    for (int j = i; j < x.size() - 1; j++)
	x[j] = x[j + 1];
    x.pop_back();
  }
  
  pyobject * & operator[](int i) { return x[i]; }
  void set(int i, pyobject & obj) { x[i] = &obj; }
  pytype & type() { return _type; }

private:
  std::vector< pyobject * > x;
  static pytype & _type;
};

#endif
