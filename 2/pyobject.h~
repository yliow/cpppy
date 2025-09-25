//=============================================================================
// pyobject and p_pyobject
//
// p_pyobject contains a pointer to pyobject.
// All methods in pyobject are supported in p_pyobject.
// The corresponding methods in p_pyobject delegates to the correct method
// in pyobject.
//=============================================================================

#ifndef PYOBJECT_H
#define PYOBJECT_H

#include "include.h"

class pyobject
{
public:
    int id() const;
    virtual std::string __repr__() const;
    virtual pytype & type() const;
    virtual bool operator==(const pyobject &) const;
    virtual bool operator!=(const pyobject &) const;

//private:
    static pytype * _type;
};


std::ostream & operator<<(std::ostream &, const pyobject &);
int id(const pyobject &);
pytype & type(const pyobject &);
std::string str(const pyobject &);
std::string debug(const pyobject &);


//=============================================================================
// p_pyobject
//=============================================================================
class p_pyobject;
typedef p_pyobject _;
class p_pyobject
{
public:
    p_pyobject(pyobject *);
    virtual pyobject & deref() const;
    //void operator=(const p_pyobject &);
    virtual std::string __repr__() const;
    virtual p_pytype & type() const;
    virtual bool operator==(const p_pyobject &) const;
    virtual bool operator!=(const p_pyobject &) const;

    virtual void operator+=(const p_pyobject &) {}
    
//private:
    pyobject * _p;
    static p_pytype * _type;
};

typedef p_pyobject _;

std::ostream & operator<<(std::ostream &, const _ &);
int id(const _ & x);
std::string str(const _ &);
std::string debug(const _ &);

#endif
