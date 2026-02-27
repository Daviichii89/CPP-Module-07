#include <iostream>
#include <string>
#include "iter.hpp"

// --- Test functions ---

// Prints any element (takes by const ref: read-only)
template <typename T>
void printElem(T const& x)
{
    std::cout << x << std::endl;
}

// Increments an int (takes by non-const ref: modifies)
void increment(int& x)
{
    x += 1;
}

// Converts a char to uppercase (modifies)
void toUpper(char& c)
{
    if (c >= 'a' && c <= 'z')
        c = c - 'a' + 'A';
}

int main(void)
{
    // Test 1: int array with instantiated function template
    std::cout << "=== int array (print) ===" << std::endl;
    int nums[] = {1, 2, 3, 4, 5};
    ::iter(nums, 5, printElem<int>);

    // Test 2: function that modifies the elements
    std::cout << "=== int array (increment) ===" << std::endl;
    ::iter(nums, 5, increment);
    ::iter(nums, 5, printElem<int>);

    // Test 3: std::string array
    std::cout << "=== string array (print) ===" << std::endl;
    std::string words[] = {"hola", "mundo", "templates"};
    ::iter(words, 3, printElem<std::string>);

    // Test 4: const array -> function that only reads
    std::cout << "=== const int array (print) ===" << std::endl;
    const int consts[] = {10, 20, 30};
    ::iter(consts, 3, printElem<int>);

    // Test 5: char array with function that modifies
    std::cout << "=== char array (toUpper) ===" << std::endl;
    char letters[] = {'a', 'b', 'c', 'd'};
    ::iter(letters, 4, toUpper);
    ::iter(letters, 4, printElem<char>);

    return 0;
}
