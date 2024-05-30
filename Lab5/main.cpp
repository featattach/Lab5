#include "StringClass.h"

int main() {
    StringClass str1("Hello");
    StringClass str2("World");
    StringClass str3 = str1 + str2;

    str1.print();
    str2.print();
    str3.print();

    if (str1 == str2) {
        std::cout << "Strings are equal" << std::endl;
    }
    else {
        std::cout << "Strings are not equal" << std::endl;
    }

    return 0;
}
