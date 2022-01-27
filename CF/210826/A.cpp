#include <iostream>
int main() {
    int t;
    std::cin >> t;
    while (t--)
    {
        int l, r;
        std::cin >> l >> r;
        if (l < r / 2 + 1)
            std::cout << r % (r / 2 + 1) << std::endl;
        else
            std::cout << r % l << std::endl;
    }
    
    return 0;
}