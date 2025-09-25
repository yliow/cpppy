#include "include.h"

//pytype * pyobject::_type(NULL);
pytype * pyobject::_type(new pytype("object"));
//void pyobject::init()
//{
//    _type = new pytype("object");
//}


int pyobject::id() const
{
    return int(this);
}


std::string pyobject::__repr__() const
{
    return "<object>";
}


pytype & pyobject::type() const
{
    return *_type;
}


std::ostream & operator<<(std::ostream & c, const pyobject & x)
{
    return (c << x.__repr__());
}


int id(const pyobject & obj) 
{ 
    return obj.id(); 
}


pytype & type(const pyobject & x)
{ 
    return x.type(); 
}


std::string str(const pyobject & obj) 
{ 
    return obj.__repr__(); 
}


std::string debug(const pyobject & p)
{ 
    char t[100];
    sprintf(t, "<debug: %s, %s, id:%d>",
            str(p).c_str(),
            str(p.type()).c_str(),
            p.id());
    return std::string(t);
}

bool pyobject::operator==(const pyobject & t) const
{
    return __repr__() == t.__repr__();
}

bool pyobject::operator!=(const pyobject & t) const
{
    return !(__repr__() == t.__repr__());
}

//--------------------------------------------------------------------------
// Definitions for p_pyobject
//--------------------------------------------------------------------------
//p_pytype * p_pyobject::_type(NULL);
p_pytype * p_pyobject::_type(new p_pytype(pyobject::_type));

//void p_pyobject::init()
//{
//    _type = new p_pytype(pyobject::_type);
//}


p_pyobject::p_pyobject(pyobject * p) : _p(p)
{}


pyobject & p_pyobject::deref() const
{
    return *_p;
}


p_pytype & p_pyobject::type() const
{
    return *_type;
}

std::string p_pyobject::__repr__() const
{
    return deref().__repr__();
}

std::ostream & operator<<(std::ostream & c, const _ & x)
{
    return (c << x.deref());
}


int id(const _ & x) 
{ 
    return id(x.deref()); 
}


std::string str(const _ & x) 
{ 
    return str(x.deref());
}


std::string debug(const _ & x)
{
    return debug(x.deref());
}

bool p_pyobject::operator==(const p_pyobject & x) const
{
    return (deref() == x.deref());
}

bool p_pyobject::operator!=(const p_pyobject & x) const
{
    return !(*this == x);
}
