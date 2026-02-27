#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Array.hpp"

#define MAX_VAL 5
int main(void)
{
    // Subject tests
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        std::cout << "adding in array numbers the value " << value << " in position " << i << std::endl;
        numbers[i] = value;
        std::cout << "adding in array mirror the value " << value << " in position " << i << std::endl;
        mirror[i] = value;
    }
    std::cout << "\n----------------------------\n" << std::endl;
    {
        std::cout << "creating tmp and test" << std::endl;
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "tmp and test created" << std::endl;
    }
    std::cout << "\n----------------------------\n" << std::endl;
    for (int i = 0; i < MAX_VAL; i++) {
        std::cout << "checking position in numbers " << i << ": " << numbers[i] << std::endl;
        std::cout << "checking position in mirror " << i << ": " << mirror[i] << std::endl;
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "\n----------------------------\n" << std::endl;
    try {
        std::cout << "Trying to access numbers[-2]" << std::endl;
        numbers[-2] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    std::cout << "\n----------------------------\n" << std::endl;
    try {
        std::cout << "Trying to access numbers[MAX_VAL - 1]" << std::endl;
        numbers[MAX_VAL - 1] = 0;
        std::cout << "  -> The value at numbers[MAX_VAL - 1] is: " << numbers[MAX_VAL - 1] << std::endl;
        std::cout << "Trying to access numbers[MAX_VAL]" << std::endl;
        numbers[MAX_VAL] = 0;
        std::cout << "  -> The value at numbers[MAX_VAL] is: " << numbers[MAX_VAL] << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n----------------------------\n" << std::endl;
    for (int i = 0; i < MAX_VAL; i++){
        std::cout << "i: " << i << std::endl;
        numbers[i] = rand();
    }
    delete [] mirror;
    std::cout << "\n=== Default constructor ===" << std::endl;
    Array<int> empty;
    std::cout << "size: " << empty.size() << std::endl;

    std::cout << "\n=== Constructor with n=5 ===" << std::endl;
    Array<int> nums(5);
    std::cout << "size: " << nums.size() << std::endl;
    for (unsigned int i = 0; i < nums.size(); i++)
        std::cout << "nums[" << i << "] = " << nums[i] << std::endl;

    std::cout << "\n=== Modify elements ===" << std::endl;
    for (unsigned int i = 0; i < nums.size(); i++)
        nums[i] = static_cast<int>(i * 10);
    for (unsigned int i = 0; i < nums.size(); i++)
        std::cout << "nums[" << i << "] = " << nums[i] << std::endl;

    std::cout << "\n=== Copy constructor (deep copy) ===" << std::endl;
    Array<int> copy(nums);
    copy[0] = 999;
    std::cout << "nums[0] = " << nums[0] << " (must still be 0)" << std::endl;
    std::cout << "copy[0] = " << copy[0] << " (must be 999)" << std::endl;

    std::cout << "\n=== Assignment operator (deep copy) ===" << std::endl;
    Array<int> assigned;
    assigned = nums;
    assigned[1] = 777;
    std::cout << "nums[1]     = " << nums[1]     << " (must be 10)" << std::endl;
    std::cout << "assigned[1] = " << assigned[1] << " (must be 777)" << std::endl;

    std::cout << "\n=== Out-of-bounds access ===" << std::endl;
    try {
        std::cout << nums[10] << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Empty array, access [0] ===" << std::endl;
    try {
        std::cout << empty[0] << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Array<std::string> ===" << std::endl;
    Array<std::string> words(3);
    words[0] = "hola";
    words[1] = "mundo";
    words[2] = "templates";
    for (unsigned int i = 0; i < words.size(); i++)
        std::cout << "words[" << i << "] = " << words[i] << std::endl;

    std::cout << "\n=== const Array<int> ===" << std::endl;
    const Array<int> constArr(nums);
    std::cout << "constArr[0] = " << constArr[0] << std::endl;
    // constArr[0] = 42;  // would not compile: const T&

    return 0;
}
