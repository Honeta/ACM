#include <stdio.h>
#include <iostream>
#include <string>
auto func() {
    return std::string("he");
}
int main() {
    std::cout << func();
    return 0;
}