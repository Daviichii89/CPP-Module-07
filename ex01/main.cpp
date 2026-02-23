#include <iostream>
#include <string>
#include "iter.hpp"

// --- Funciones de prueba ---

// Imprime cualquier elemento (toma por const ref: solo lectura)
template <typename T>
void printElem(T const& x)
{
    std::cout << x << std::endl;
}

// Incrementa un entero (toma por ref no-const: modifica)
void increment(int& x)
{
    x += 1;
}

// Convierte un char a mayusculas (modifica)
void toUpper(char& c)
{
    if (c >= 'a' && c <= 'z')
        c = c - 'a' + 'A';
}

int main(void)
{
    // Test 1: array de int con funcion template instanciada
    std::cout << "=== int array (print) ===" << std::endl;
    int nums[] = {1, 2, 3, 4, 5};
    ::iter(nums, 5, printElem<int>);

    // Test 2: funcion que modifica los elementos
    std::cout << "=== int array (increment) ===" << std::endl;
    ::iter(nums, 5, increment);
    ::iter(nums, 5, printElem<int>);

    // Test 3: array de std::string
    std::cout << "=== string array (print) ===" << std::endl;
    std::string words[] = {"hola", "mundo", "templates"};
    ::iter(words, 3, printElem<std::string>);

    // Test 4: array const -> funcion que solo lee
    std::cout << "=== const int array (print) ===" << std::endl;
    const int consts[] = {10, 20, 30};
    ::iter(consts, 3, printElem<int>);

    // Test 5: array de char con funcion que modifica
    std::cout << "=== char array (toUpper) ===" << std::endl;
    char letters[] = {'a', 'b', 'c', 'd'};
    ::iter(letters, 4, toUpper);
    ::iter(letters, 4, printElem<char>);

    return 0;
}
