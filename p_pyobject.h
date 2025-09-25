/*

Pointer to pyobject

Methods and operators:
Case 1: x, y have p_pyobject type
Case 2: x has p_pyobject type and y has pyobject type

x = y   Case 1: x._p = y._p
        Case 2: *x._p = y

x += y  Case 1: *x._p += *y._p
        Case 2: *x._p += y

Note however that if x corresponds to an immutable type,
then 

Case 1

Meaning of x = y:
--------------------------------------------------------
    \  x        pyint          p_pyint
y    \ 
----------+---------------------------------------------
pyint     |     x.v = y.v         *(x.p) = y  static/immutable
          |                    OR x.p = &y    dynamic/mutable
----------+---------------------------------------------
p_pyint   |     x = *(y.p)        *(x.p) = *(y.p) static/immutable
          |                    OR x.p = y.p       dynamic/mutable
----------+---------------------------------------------

Problem: what if *x._p does not have operator+=.
Combinatorial explosion.
It depends on pyobject value pointed to!
So each pyobject subclass must come with a pointer version.
For instance

   pyobject ......> p_pyobject
   |                |
   |                | 
   pyint .........> p_pyint

Note that user should only use pyint. p_pyint should only be used
by pylist, pydict, pytuple, etc.

Note that all the above containers should use p_pyobject.
pylist should be a vector of p_object.

What happens when you do: x.append(y)?
--------------------------------------------------------
    \  x        pylist          p_pylist
y    \ 
----------+---------------------------------------------
pyint     |     x.v = y.v         *(x.p) = y  static/immutable
          |                    OR x.p = &y    dynamic/mutable
----------+---------------------------------------------
p_pyint   |     x = *(y.p)        *(x.p) = *(y.p) static/immutable
          |                    OR x.p = y.p       dynamic/mutable
----------+---------------------------------------------

What about pylist of pylist?
Therefore pylist must have p_pylist.
 */

#ifndef P_PYOBJECT_H
#define P_PYOBJECT_H

#include "pyobject.h"

class p_pyobject
{
 public:
  pyobject * _p;
};

#endif
