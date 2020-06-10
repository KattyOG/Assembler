#include <iostream>

int main()
{
    float a = 1.44f;
    float b = 5.34f;
    float res;
    __asm__(
            "fld %1;"
            "fld %2;"
            "fadd;"
            "fstp %0;":
            "=m"(res):"g"(a),"g"(b));
    std::cout<<a<<" + "<<b<<" = "<<res<<std::endl;
}
