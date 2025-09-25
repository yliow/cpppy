#ifndef PYOBJECT_H
#define PYOBJECT_H


class pytype;

class pyobject
{
 public:
  pytype * f()
    {
      return new pytype();
    }
};

class pytype: public pyobject
{};


#endif
