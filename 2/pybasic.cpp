#include "include.h"

pytype * pyint::_type(new pytype("int"));
pytype & pyint::type() const
{
    return *_type;
}

pytype * pyfloat::_type(new pytype("float"));
pytype & pyfloat::type() const
{
    return *_type;
}

pytype * pystr::_type(new pytype("str"));
pytype & pystr::type() const
{
    return *_type;
}

pytype * pylist::_type(new pytype("list"));
pytype & pylist::type() const
{
    return *_type;
}

std::string pylist::__repr__() const
{
    return "<list>";
}

