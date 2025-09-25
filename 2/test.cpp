#include "include.h"
#include "pybasic.h"

int main()
{
    {
        std::cout << "\ntesting pyobject ...\n";
        pyobject x;
        std::cout << x << std::endl;
        std::cout << debug(x) << std::endl;
        std::cout << x.type() << std::endl;
        std::cout << type(x) << std::endl;
        _ y(&x);
        std::cout << y << std::endl;
        std::cout << "debug(y):" << debug(y) << std::endl;
        std::cout << "debug(y.type()): " << debug(y.type()) << std::endl;
    }

    {
        std::cout << "\ntesting pybasic/pyint ...\n";
        pyint x = 43;
        std::cout << "x: " << x << std::endl;
        std::cout << "id(x): " << id(x) << std::endl;
        std::cout << x.type() << std::endl;
        std::cout << type(x) << std::endl;
        std::cout << "debug(x): " << debug(x) << std::endl;
        //x += 1;
        //std::cout << x << std::endl;
        //_ y(&x);
        //_ z(&x);
        //y += z;
        //std::cout << y << std::endl;
        //std::cout << "debug(y):" << debug(y) << std::endl;
        //std::cout << "debug(y.type()): " << debug(y.type()) << std::endl;  
    }
    
    {
        std::cout << "\ntesting pyfloat ...\n";
        pyfloat x = 3.14;
        std::cout << "x: " << x << std::endl;
        std::cout << "id(x): " << id(x) << std::endl;
        std::cout << x.type() << std::endl;
        std::cout << type(x) << std::endl;
        std::cout << "debug(x): " << debug(x) << std::endl;
    }
    
    {
        std::cout << "\ntesting pystr ...\n";
        pystr x("hello world"); 
        std::cout << "x: " << x << std::endl;
        std::cout << "id(x): " << id(x) << std::endl;
        std::cout << x.type() << std::endl;
        std::cout << type(x) << std::endl;
        std::cout << "debug(x): " << debug(x) << std::endl;
    }
    
    {
        std::cout << "\ntesting p_pystr ...\n";
        pystr x("hello world");
        std::cout << "x: " << x << std::endl;
        std::cout << "id(x): " << id(x) << std::endl;
        std::cout << x.type() << std::endl;
        std::cout << type(x) << std::endl;
        std::cout << "debug(x): " << debug(x) << std::endl;
    }
    
    {
        std::cout << "\ntesting dynamic typing ...\n";
        
        pystr x("hello world");
        _ xr(&x);
        std::cout << "debug(xr): " << debug(xr) << std::endl;

        pyint y = 42;
        _ yr(&y);
        xr = yr;
        std::cout << "debug(xr): " << debug(xr) << std::endl;
    }
    
    {
        std::cout << "\ntesting pylist ...\n";
        //pylist x; 
        //std::cout << "x: " << x << std::endl;
        //std::cout << "id(x): " << id(x) << std::endl;
        //std::cout << x.type() << std::endl;
        //std::cout << type(x) << std::endl;
        //std::cout << "debug(x): " << debug(x) << std::endl;
    }
    
    
    return 0;
}
