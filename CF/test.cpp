#include <iostream>
#include <vector>


int main() {
    for (int i = 9; i < 300; i++)
    if (i % 8 == 300 % i )
      std::cout << i << ' ' << i % 8 << ' ' << 300 % i << std::endl;
    return 0;
}