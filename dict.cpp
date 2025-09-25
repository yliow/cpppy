#ifndef DICT_H
#define DICT_H

#include <iostream>
#include <vector>
#include <string>

#include "pyobject.h"
pyobject None;

class keyvalue
{
public:
  //keyvalue(std::string & x, pyobject & y) : key(x), val(y) {}
  keyvalue() : key(""), val(None) {}
  //keyvalue(keyvalue & kv)
  //{
  //  key = kv.key; val = kv.val;
  //}
  void operator=(keyvalue & kv)
  {
    key = kv.key; val = kv.val;
  }
  std::string key;
  pyobject & val;
};

//template< class X >
class _dict
{
public: 
  pyobject & operator[](const std::string & key)
  {
    for (int i = 0; i < v.size(); i++)
      {
	if (v[i]->key == key)
	  {
	    return v[i]->val;
	  }
      }
    // of course need to release
    std::cout << "1...\n";
    keyvalue * kv;
    std::cout << "2...\n";
    kv = new keyvalue();
    std::cout << "3...\n";
    kv->key = key;
    std::cout << "3...\n";
    v.push_back(kv);
    std::cout << "4...\n";
    return v[v.size() - 1]->val; 
  }

  std::string __repr__() const
  {
    std::string s = "{";
    if (v.size() > 0)
      {
	s += v[0]->key + ":" + v[0]->val.__repr__();
	for (int i = 1; i < v.size(); i++)
	  {
	    s += std::string(", ") + 
	      v[i]->key + ":" + v[i]->val.__repr__();
	  }
      }
    s += "}";
    return s;
  }

private:  std::vector< keyvalue * > v;
};


#include "pystr.h"
#include "pyobject.h"
class pydict: public pyobject
{
public:

  pyobject & operator[](pyobject & key)
  {
    return d[key.__repr__()];
  }

  pyobject & operator[](const std::string key)
  {
    pystr s(key);
    return (*this)[s];
  }
  
  std::string __repr__() const
  {
    return d.__repr__();
  }

private:
  _dict d;
};


#include "pynumeric.h"
#include "pystr.h"


int main()
{
  pydict d;
  pystr s("hello world");
  pyint i(42), j(9999);
  pystr t("whoa");
  pyfloat u(3.14159);

  std::cout << debug(&s) << '\n' << std::endl;

  std::cout << d << std::endl;
  d[s] = i;
  std::cout << "10...\n";
  std::cout << &(d[s]) << "#####" << std::endl;
  //std::cout << d << std::endl;
  std::cout << "15...\n";

  //std::cout << d[s] << std::endl;
  //std::cout << d["hello world"] << std::endl;

  /*
  d[s] = &j;
  std::cout << *(d[s]) << std::endl;
  std::cout << *(d["hello world"]) << std::endl;

  d[s] = &t;
  std::cout << *(d[s]) << std::endl;
  std::cout << *(d["hello world"]) << std::endl;

  d[s] = &u;
  std::cout << *(d[s]) << std::endl;
  std::cout << *(d["hello world"]) << std::endl;

  d[s] = new pyint(3);
  std::cout << *(d[s]) << std::endl;
  std::cout << *(d["hello world"]) << std::endl;

  d["pi"] = &u;
  d["astring"] = &t;

  {
    pyobject * i = new pyint(5);
    pyobject * j = new pyint(6);
    //d["e"] = new pyint(5);
    //d["f"] = new pyint(6);
    std::cout << pyint(5) + pyint(6) << std::endl;
    std::cout << *i + *j << std::endl;
    std::cout << i->operator+(*j) << std::endl;
    //std::cout << *(d["e"]) + *(d["f"]) << std::endl;
  }
  std::cout << d << std::endl;
  */
}

#endif
