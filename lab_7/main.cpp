#include <string.h>
#include <iostream>

extern "C"
{
int string_copy(const char* dest, const char* src, unsigned long long int len);
}

int main()
{
    std::string from;
    std::string to;
    std::size_t len;

    std::cout<<"From:" << std::endl;
    std::cin >> from;
    __asm__(".intel_syntax noprefix     \n\t"
            "xor  rax, rax              \n\t"
            "cld                        \n\t"
            "xor  rcx, rcx              \n\t"
            "dec  rcx                   \n\t"
            "repne   scasb              \n\t"
            "not     rcx                \n\t"
            "dec     rcx                \n\t"
    :"=c"(len)
    :"D"(from.c_str())
    :"rax");

    int sizeOfCopy;
    std::cout << "Length: " << len << std::endl;

    std::cout << "Input number of coping symbols:";
    std::cin >> sizeOfCopy;
    to.resize(sizeOfCopy);
    string_copy(&to[0], &from[0], sizeOfCopy);

    std::cout << "Copied string:" << to << std::endl;

    return 0;
}
