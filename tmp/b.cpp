#include <iostream>
#include <string>
#include <vector>

inline std::string itoa(int i)
{
    char s[100];
    sprintf(s, "%d", i);
    return std::string(s);
}

inline std::string dtoa(double d)
{
    char s[100];
    sprintf(s, "%f", d);
    return std::string(s);
}


class object;
class pyint;
class pyfloat;
class pystr;
//=============================================================================
// p_object
//=============================================================================
class p_object
{
public:
  // can i make p_object a template class so that each of these 
  // can be moved to template subclasses instead of putting
  // everything here is a monolithic mess??
  void operator=(pyfloat &);
  void operator=(pystr &);
  void operator=(char s[]);

  object * _p;
  p_object(object *);
  p_object() : _p(NULL) {}
  p_object(int i) { *this = i; }
};
typedef p_object _; // alias for p_object


class object
{
public:
  p_object ptr();
 virtual std::string __repr__() const { return std::string("<object>"); }
};

inline p_object::p_object(object * p) : _p(p) {}
inline p_object object::ptr() { return p_object(this); }
inline std::ostream & operator<<(std::ostream & c, const object & p)
{
  return (c << p.__repr__());
}

inline std::ostream & operator<<(std::ostream & c, const p_object & p)
{
  return (c << p._p->__repr__()); // return (c << p._p);
}




class pyint: public object
{
public:
  pyint(int i) : _x(i) {}
  pyint operator+(const pyint & i) { return pyint(_x + i._x); }
  std::string __repr__() const { return itoa(_x); }
  int _x;
};
p_object & operator=(p_object & x, int i)
{
  x._p = new pyint(i);
}





class pyfloat: public object
{
public:
  pyfloat(double i) : _x(i) {}
  pyfloat operator+(const pyfloat & i) {  return pyfloat(_x + i._x); }
  double _x;
  std::string __repr__() const { return dtoa(_x); }
};
p_object & operator=(p_object x, double d)
{
  x._p = new pyfloat(d);
}




class pystr: public object
{
public:
  pystr(const std::string & s) : _x(s) {}
  std::string operator+(const pystr & i) { return (_x + i._x); }
  std::string _x;
  std::string __repr__() const { return _x; }
};
p_object & operator=(p_object x, const std::string & s)
{
  x._p = new std::string(s);
}



class pylist: public object
{
public:
  void append(object & x)
  {
    _x.push_back(x.ptr());
  }
  p_object & operator[](int i)
  {
    return _x[i];
  }
  std::string __repr__() const
  {
    std::string s("[");
    if (_x.size() > 0)
      {
	s += (_x[0]._p)->__repr__();
	for (int i = 1; i < _x.size(); i++)
	  {
	    s += ", ";
	    s += (_x[i]._p)->__repr__();
	  }
      }
    s += "]";
    return s;
  }

  std::vector< p_object > _x;
};

inline std::ostream & operator<<(std::ostream & c, 
				 const pylist & p)
{
  return (c << p.__repr__());
}




int main()
{
  object x;
  p_object p = x.ptr();

  std::cout << "0 ..." << std::endl;
  std::cout << &x << std::endl;
  std::cout << p << std::endl;

  std::cout << "1 ..." << std::endl;
  pyint i = 42;
  pyint j = 1;
  std::cout << i << std::endl;
  std::cout << i + j << std::endl;
  std::cout << i + 1 << std::endl;


  pyfloat k = 3.14;
  pyfloat l = 2.71;
  std::cout << k << ' ' << l << std::endl;
  std::cout << k + l << std::endl;
  std::cout << k + 1.1 << std::endl;

  pystr s("hello world");
  std::cout << s << std::endl;

  pylist xs;
  std::cout << xs << std::endl;

  xs.append(i);
  std::cout << xs << std::endl;

  xs.append(s);
  std::cout << xs << std::endl;

  xs[0] = j;
  std::cout << xs << std::endl;

  xs[1] = k;
  std::cout << xs << std::endl;

  xs[0] = 3;
  std::cout << xs << std::endl;

  pylist ys;
  ys.append(i);
  ys.append(j);
  ys.append(k);
  std::cout << ys << std::endl;
  ys.append(xs);
  std::cout << ys << std::endl;
  ys.append(s);
  std::cout << ys << std::endl;

  /* use case */
  {
    _ z = 1;
    std::cout << z << "\n";
    z = "hello world";
    std::cout << z << "\n";
  }
  return 0;
}
