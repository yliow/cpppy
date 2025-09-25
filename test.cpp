//#include "include.h"

#include <iostream>

#include "pyobject.h"
#include "pytype.h"
#include "pynumeric.h"
#include "pystr.h"
#include "pylist.h"


std::string passfail(bool b){ return (b ? "pass " : "fail "); }

class passfailprinter
{
public:
  static std::ostream & c;
};
std::ostream & passfailprinter::c(std::cout);

passfailprinter & operator<<(passfailprinter & p, bool b)
{
  p.c << passfail(b);
  return p;
}

passfailprinter & operator<<(passfailprinter & p, const std::string & s)
{
  p.c << s;
  return p;
}

#define NEWLINE std::cout << std::endl;


int main()
{
  passfailprinter p;

  {
    std::cout << "testing pytype ...\n" ;
    pyobject x;
    std::cout << type(x) << std::endl;
    pystr y;
    std::cout << type(y) << std::endl;
    pyint i = 1;
    std::cout << type(i) << std::endl;
    pyfloat j = 3.14;
    std::cout << type(j) << std::endl;
  }
  {
    std::cout << "testing pyobject ... ";
    pyobject x;
    std::cout << passfail(id(x) == int(&x))
	      << passfail(x.__repr__() == std::string("")); 
    NEWLINE;
  }
  { 
    /*
    std::cout << "testing pytype ... ";
    p << (str(pyobject::type()) == "<type \"object\">")
      << (str(pyint::type()) == "<type \"int\">")
      << (str(pyfloat::type()) == "<type \"float\">")
      << (str(pystrtype) == "<type \"str\">")
      ; // << (str(pynonetype) == "<type \"NoneType\">");
    NEWLINE;
    */
  }
  {
    /*
    std::cout << "testing pyint ... ";
    pyint x = 2, y = 3;
    p << (str(x) == "2")
      << (x + y == 5)
      << (x - y == -1)
      << (x * y == 6)
      << (x.type() == pyinttype);
    x = y;
    p << (x == 3);
    NEWLINE;
    */
  }
  {
    /*
    std::cout << "testing pyfloat ... ";
    pyfloat x = 2, y = 3;
    p << (x + y == 5)
      << (x - y == -1)
      << (x * y == 6)
      << (x.type() == pyfloattype);
    NEWLINE;
    */
  }
  {
    /*
    std::cout << "testing pystr ... ";
    pystr s("hello world");
    pystr t("abc");
    p << (str(s) == "hello world")
      << (type(s) == pystrtype);
    s = t;
    p << (str(s) == "abc");
    NEWLINE;
    */
  }

  {
    /*
    pyint x = 0;
    pyint y = 1;
    pyfloat z = 3.14159;
    pylist xs;
    std::cout << xs << std::endl;
    xs.append(&x);
    std::cout << xs << std::endl;
    xs.append(&y);
    std::cout << xs << std::endl;

    pystr s("hi");
    xs.append(&s);
    std::cout << xs << std::endl;

    xs.append(std::string("world"));
    std::cout << xs << std::endl;

    xs.append("hello world");
    std::cout << xs << std::endl;

    xs.append(42);
    std::cout << xs << std::endl;

    xs.append(3.14159);
    std::cout << xs << std::endl;

    std::cout << "del ...\n";

    xs.del(0);
    std::cout << xs << std::endl;
    
    xs.del(0);
    std::cout << xs << std::endl;
    xs.del(0);
    std::cout << xs << std::endl;
    xs.del(0);
    std::cout << xs << std::endl;
    
    pyobject & t = xs[0];
    std::cout << t << std::endl;
    
    xs.append(t);
    std::cout << xs << std::endl;
    
    pylist ys;
    ys.append(x);
    ys.append(xs);
    std::cout << ys << std::endl;
    
    std::cout << "type of xs: " << xs.type() << std::endl;
    std::cout << "type of ys: " << ys.type() << std::endl;
    */
  }

  {
    /*
      std::cout << "============== ...\n\n";
      pylist xs;
      pyint i = 42;
      //std::cout << debug(i) << std::endl;
      xs.append(i);
      xs.append(43);
      xs.append("hello world");
      std::cout << "xs: " << xs << std::endl;
      
      pyint j = 99;
      //std::cout << "j:" << debug(j) << std::endl;
      
      xs[0] = &j; //xs.set(0, j);  
      std::cout << "xs: " << xs << std::endl;
      
      xs[0] = &i;
      std::cout << "xs: " << xs << std::endl;
      
      xs.set(0, 45);
      
      //xs.del(0);
      //std::cout << "xs: " << xs << std::endl;
      //xs.del(1);
      //std::cout << "xs: " << xs << std::endl;
      //std::cout << "type of xs: " << xs.type() << std::endl;
      //std::cout << "type of xs[0]: " << xs[0].type() << std::endl;
      */
  }
  return 0;
}
