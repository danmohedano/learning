#include <iomanip>
#include <iostream>

int main()
{
    std::cout << std::left; // left justify output 
    std::cout << std::setw(16) << "bool:" << sizeof(bool) << "B\n"; 
    std::cout << std::setw(16) << "char:" << sizeof(char) << "B\n"; 
    std::cout << std::setw(16) << "short:" << sizeof(short) << "B\n"; 
    std::cout << std::setw(16) << "int:" << sizeof(int) << "B\n"; 
    std::cout << std::setw(16) << "long:" << sizeof(long) << "B\n"; 
    std::cout << std::setw(16) << "long long:" << sizeof(long long) << "B\n"; 
    std::cout << std::setw(16) << "float:" << sizeof(float) << "B\n"; 
    std::cout << std::setw(16) << "double:" << sizeof(double) << "B\n"; 
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << "B\n"; 
}
