#include "pytype.h"
#include "pynumeric.h"

//pytype * pynumeric<int>::_type(new pytype("int"));
//pytype * pynumeric<float>t::_type(new pytype("float"));

pytype pyinttype = *(new pytype("int"));
pytype pyfloattype = *(new pytype("float"));
