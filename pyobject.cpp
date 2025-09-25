#include "pyobject.h"
#include "pytype.h"

pyobject None;

pytype * pyobject::_type(new pytype("object"));
