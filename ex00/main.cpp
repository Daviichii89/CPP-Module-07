#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void)
{
    // Test con int (del enunciado)
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

    // Test con std::string (del enunciado)
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

    // Test caso de igualdad: min y max deben devolver el segundo
    int x = 5;
    int y = 5;
    std::cout << "min( 5, 5 ) = " << ::min(x, y) << std::endl;
    std::cout << "max( 5, 5 ) = " << ::max(x, y) << std::endl;

    // Test con double
    double p = 3.14;
    double q = 2.71;
    ::swap(p, q);
    std::cout << "p = " << p << ", q = " << q << std::endl;
    std::cout << "min( p, q ) = " << ::min(p, q) << std::endl;
    std::cout << "max( p, q ) = " << ::max(p, q) << std::endl;

    return 0;
}
