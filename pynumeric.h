#ifndef PYNUMERIC_H
#define PYNUMERIC_H

#include <iostream>
#include <string>
#include <vector>

#include "pyobject.h"

//=============================================================================
// pynumeric, pyint, pyfloat
//=============================================================================

template < class T >
class pynumeric_exception
{};
typedef pynumeric_exception<float> pyfloat_exception;

template < class T >
class pynumeric: public pyobject
{
public:
  pynumeric(T x = 0) : _x(x) {}

    pynumeric & operator=(const pynumeric & obj)
      {
	_x = obj._x;
      }
        
  pynumeric operator+=(const pynumeric & obj) { return pynumeric(_x += obj._x); }
  pynumeric operator-=(const pynumeric & obj) { return pynumeric(_x -= obj._x); }
  pynumeric operator*=(const pynumeric & obj) { return pynumeric(_x *= obj._x); }
  pynumeric operator/=(const pynumeric & obj) { return pynumeric(_x /= obj._x); }
  pynumeric operator%=(const pynumeric & obj) { return pynumeric(_x %= obj._x); }
  pynumeric operator+(const pynumeric & obj) const { return pynumeric(_x + obj._x); }
  pynumeric operator-(const pynumeric & obj) const { return pynumeric(_x - obj._x); }
  pynumeric operator*(const pynumeric & obj) const { return pynumeric(_x * obj._x); }
  pynumeric operator/(const pynumeric & obj) const { return pynumeric(_x / obj._x); }
  pynumeric operator%(const pynumeric & obj) const { return pynumeric(_x % obj._x); }

  bool operator==(const pynumeric & obj) const { return _x == obj._x; }
  bool operator!=(const pynumeric & obj) const { return !(_x == obj._x); }
  bool operator<(const pynumeric & obj) const { return _x < obj._x; }
  bool operator<=(const pynumeric & obj) const { return _x <= obj._x; }
  bool operator>(const pynumeric & obj) const { return _x > obj._x; }
  bool operator>=(const pynumeric & obj) const { return _x >= obj._x; }

  std::string __repr__() const;

                           //pytype & type() { return type(*this); }
  T _x;
  //static pytype * _type; // something's wrong: g++ does not 
                           // allow instantiation of static template members

  pytype & type();
};

//=============================================================================
// pyint
//=============================================================================
typedef pynumeric<int> pyint;
inline std::string pyint::__repr__() const
{
    char s[100];
    sprintf(s, "%d", _x);
    return std::string(s);
}
inline pyint operator+(int i, const pyint & obj) { return obj + i; }
inline pyint operator-(int i, const pyint & obj) { return obj - i; }
inline pyint operator*(int i, const pyint & obj) { return obj * i; }
inline pyint operator/(int i, const pyint & obj) { return obj / i; }
inline pyint operator%(int i, const pyint & obj) { return obj % i; }
extern pytype pyinttype;
inline pytype & pyint::type() { return pyinttype; }

//=============================================================================
// pyfloat
//=============================================================================
typedef pynumeric<double> pyfloat;
inline std::string pyfloat::__repr__() const
{
    char s[100];
    sprintf(s, "%f", _x);
    return std::string(s);
}
inline pyfloat operator+(double i, const pyfloat & obj) { return obj + i; }
inline pyfloat operator-(double i, const pyfloat & obj) { return obj - i; }
inline pyfloat operator*(double i, const pyfloat & obj) { return obj * i; }
inline pyfloat operator/(double i, const pyfloat & obj) { return obj / i; }
inline pyfloat operator%(double i, const pyfloat & obj) { throw pyfloat_exception(); }
extern pytype pyfloattype;
inline pytype & pyfloat::type() { return pyfloattype; }

inline std::string str(int i) { return str(pyint(i)); }
inline std::string str(double i) { return str(pyfloat(i)); }
inline std::string str(char s[]) { return std::string(s); }

#endif
