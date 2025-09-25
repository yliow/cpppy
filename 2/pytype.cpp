#include "pytype.h"

pytype * pytype::_type(new pytype("type"));

std::string pytype::__repr__() const
{
    return std::string("<type \"" + _x + "\">");
}

pytype & pytype::type() const
{
    return *_type;
}

p_pytype::p_pytype(pytype * p)
    : p_pyobject(p)
{}

p_pytype * p_pytype::_type(new p_pytype(pytype::_type));

p_pytype & p_pytype::type() const
{
    return *_type;
}
