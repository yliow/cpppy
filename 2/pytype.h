//=============================================================================
// pytype
// Should == be comparison based on id?
//=============================================================================

#ifndef PYTYPE_H
#define PYTYPE_H

#include "include.h"

class pytype: public pyobject
{
public:
    pytype(const std::string & s) : _x(s) {}
    virtual std::string __repr__() const;
    
    virtual pytype & type() const;
    static pytype * _type;

private:
    std::string _x;
};


class p_pytype: public p_pyobject
{
public:
    p_pytype(pytype *);
    
    virtual p_pytype & type() const;
    static p_pytype * _type;
};

#endif
