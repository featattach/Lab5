#ifndef STRINGCLASS_H
#define STRINGCLASS_H

#include <iostream>
#include <cstring>

class StringClass {
private:
    char* str;
    size_t length;

public:
    // Конструкторы
    StringClass(); // Конструктор по умолчанию
    StringClass(const char* s); // Конструктор с параметрами
    StringClass(const StringClass& other); // Конструктор копирования
    ~StringClass(); // Деструктор

    // Методы
    void print() const;
    size_t getLength() const;

    // Операторы
    StringClass& operator=(const StringClass& other);
    StringClass operator+(const StringClass& other) const;
    bool operator==(const StringClass& other) const;
    bool operator!=(const StringClass& other) const;
};

#endif
