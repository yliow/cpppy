// Template class for basic types (int, double, bool, std::string)
// Note that this can also be treated as a basic wrapper for any
// class.
//
// Objects of this class wraps a value (int/double/bool/etc.). The
// name of this attribute is _x.
//
// This class overwrites the following in pyobject:
// __repr__() this returns the string version of _x
// operator==() and operator!= uses _x for comparison

#ifndef PYBASIC_H
#define PYBASIC_H

#include "include.h"

template < class T >
class pybasic: public pyobject
{
public:
    pybasic(const T & x) : pyobject(), _x(x) {}
    pybasic() : pyobject() {}
    virtual pytype & type() const {} // not used
    virtual bool operator==(const pybasic & x) { _x == x._x; }
    virtual bool operator!=(const pybasic & x) { _x != x._x; }
    virtual std::string __repr__() const { return str(_x); }
    virtual void operator=(pybasic & x) { val() = x.val(); }
    virtual T & val() { return _x; }
    //static pytype * _type;
//private:
    T _x;
};

template < class T >
class p_pybasic: public p_pyobject
{
    p_pybasic(pybasic< T > *);
    virtual void operator=(const p_pybasic & x) { deref() = x.deref(); }
};


//-----------------------------------------------------------------------------
// pyint and p_pyint
//-----------------------------------------------------------------------------
class pyint: public pybasic<int>
{
public:
    pyint(int x) : pybasic<int>(x) {}
    //void operator+=(const pyint & x) { _x += x._x; }
    virtual pytype & type() const;
    static pytype * _type;
};
class p_pyint: public p_pybasic<int>
{
public:
    p_pyint(pyint *);
    //void operator+=(const p_pyint & x) { deref() += x.deref(); }

};




//-----------------------------------------------------------------------------
// pyfloat and p_pyfloat
//-----------------------------------------------------------------------------
class pyfloat: public pybasic<double>
{
public:
    pyfloat(double x) : pybasic<double>(x) {}
    //void operator+=(const pyfloat & x) { _x += x._x; }
    virtual pytype & type() const;
    static pytype * _type;
};
class p_pyfloat: public p_pybasic<double>
{
public:
    p_pyfloat(pyfloat *);
};




//-----------------------------------------------------------------------------
// pystr
//-----------------------------------------------------------------------------
class pystr: public pybasic<std::string>
{
public:
    pystr(const std::string & x) : pybasic<std::string>(x) {}
    //void operator+=(const pyfloat & x) { _x += x._x; }
    virtual pytype & type() const;
    static pytype * _type;
};
class p_pystr: public p_pybasic<std::string>
{
public:
    p_pystr(pystr *);
};



//-----------------------------------------------------------------------------
// pylist
//-----------------------------------------------------------------------------
class pylist: public pybasic< std::vector <p_pyobject> >
{
public:
    pylist() : pybasic<std::vector <p_pyobject> >() {}
    virtual pytype & type() const;
    static pytype * _type;

    virtual std::string __repr__() const; // see pybasic.cpp
};
class p_pylist: public p_pybasic< std::vector <p_pyobject> >
{
public:
    p_pylist(pylist *);
};

#endif
