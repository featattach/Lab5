#include "StringClass.h"

// Конструктор по умолчанию
StringClass::StringClass() : str(nullptr), length(0) {}

// Конструктор с параметрами
StringClass::StringClass(const char* s) {
    if (s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy_s(str, length + 1, s);
    }
    else {
        str = nullptr;
        length = 0;
    }
}

// Конструктор копирования
StringClass::StringClass(const StringClass& other) {
    length = other.length;
    if (other.str) {
        str = new char[length + 1];
        strcpy_s(str, length + 1, other.str);
    }
    else {
        str = nullptr;
    }
}

// Деструктор
StringClass::~StringClass() {
    delete[] str;
}

// Метод для вывода строки
void StringClass::print() const {
    if (str) {
        std::cout << str << std::endl;
    }
    else {
        std::cout << "(null)" << std::endl;
    }
}

// Метод для получения длины строки
size_t StringClass::getLength() const {
    return length;
}

// Оператор присваивания
StringClass& StringClass::operator=(const StringClass& other) {
    if (this == &other) return *this; // проверка на самоприсваивание

    delete[] str; // освобождение старой памяти

    length = other.length;
    if (other.str) {
        str = new char[length + 1];
        strcpy_s(str, length + 1, other.str);
    }
    else {
        str = nullptr;
    }
    return *this;
}

// Оператор сложения
StringClass StringClass::operator+(const StringClass& other) const {
    StringClass result;
    result.length = length + other.length;
    result.str = new char[result.length + 1];
    if (str) {
        strcpy_s(result.str, length + 1, str);
    }
    if (other.str) {
        strcat_s(result.str, result.length + 1, other.str);
    }
    return result;
}

// Оператор равенства
bool StringClass::operator==(const StringClass& other) const {
    if (length != other.length) return false;
    if (str && other.str) {
        return strcmp(str, other.str) == 0;
    }
    return str == other.str;
}

// Оператор неравенства
bool StringClass::operator!=(const StringClass& other) const {
    return !(*this == other);
}
