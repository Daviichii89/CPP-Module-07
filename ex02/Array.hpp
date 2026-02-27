#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
private:
    T*            _data;
    unsigned int  _size;

public:
    // Orthodox Canonical Form
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    // Operadores de acceso
    T&           operator[](unsigned int index);
    const T&     operator[](unsigned int index) const;

    // Informacion
    unsigned int size() const;

    // Excepcion para indice fuera de rango
    class OutOfBoundsException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

#include "Array.tpp"

#endif
