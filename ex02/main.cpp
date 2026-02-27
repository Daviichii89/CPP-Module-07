#include <iostream>
#include <string>
#include "Array.hpp"

int main(void)
{
    // Test 1: constructor por defecto -> array vacio
    std::cout << "=== Constructor por defecto ===" << std::endl;
    Array<int> empty;
    std::cout << "size: " << empty.size() << std::endl;

    // Test 2: constructor con n elementos (inicializados a 0/default)
    std::cout << "\n=== Constructor con n=5 ===" << std::endl;
    Array<int> nums(5);
    std::cout << "size: " << nums.size() << std::endl;
    for (unsigned int i = 0; i < nums.size(); i++)
        std::cout << "nums[" << i << "] = " << nums[i] << std::endl;

    // Test 3: modificar elementos con operator[]
    std::cout << "\n=== Modificar elementos ===" << std::endl;
    for (unsigned int i = 0; i < nums.size(); i++)
        nums[i] = static_cast<int>(i * 10);
    for (unsigned int i = 0; i < nums.size(); i++)
        std::cout << "nums[" << i << "] = " << nums[i] << std::endl;

    // Test 4: constructor de copia -> deep copy
    std::cout << "\n=== Constructor de copia (deep copy) ===" << std::endl;
    Array<int> copy(nums);
    copy[0] = 999;
    std::cout << "nums[0] = " << nums[0] << " (debe seguir siendo 0)" << std::endl;
    std::cout << "copy[0] = " << copy[0] << " (debe ser 999)" << std::endl;

    // Test 5: operador de asignacion -> deep copy
    std::cout << "\n=== Operador de asignacion (deep copy) ===" << std::endl;
    Array<int> assigned;
    assigned = nums;
    assigned[1] = 777;
    std::cout << "nums[1]     = " << nums[1]     << " (debe ser 10)" << std::endl;
    std::cout << "assigned[1] = " << assigned[1] << " (debe ser 777)" << std::endl;

    // Test 6: acceso fuera de limites lanza excepcion
    std::cout << "\n=== Acceso fuera de limites ===" << std::endl;
    try {
        std::cout << nums[10] << std::endl;
    } catch (std::exception& e) {
        std::cout << "Excepcion: " << e.what() << std::endl;
    }

    // Test 7: array vacio lanza excepcion en cualquier acceso
    std::cout << "\n=== Array vacio, acceso al [0] ===" << std::endl;
    try {
        std::cout << empty[0] << std::endl;
    } catch (std::exception& e) {
        std::cout << "Excepcion: " << e.what() << std::endl;
    }

    // Test 8: template con std::string
    std::cout << "\n=== Array<std::string> ===" << std::endl;
    Array<std::string> words(3);
    words[0] = "hola";
    words[1] = "mundo";
    words[2] = "templates";
    for (unsigned int i = 0; i < words.size(); i++)
        std::cout << "words[" << i << "] = " << words[i] << std::endl;

    // Test 9: const array -> solo lectura
    std::cout << "\n=== const Array<int> ===" << std::endl;
    const Array<int> constArr(nums);
    std::cout << "constArr[0] = " << constArr[0] << std::endl;
    // constArr[0] = 42;  // esto no compilaria: const T&

    return 0;
}
