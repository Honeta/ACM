#include <iostream>
#include <string>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        bool flag = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '0') {
                flag = 1;
                if (i < n / 2) 
                    std::cout << i + 1 << ' ' << n << ' ' << i + 2 << ' ' << n << std::endl;
                else
                    std::cout << 1 << ' ' << i + 1 << ' ' << 1 << ' ' << i << std::endl;
                break;
            }
        if (!flag)
            std::cout << 1 << ' ' << n / 2  << ' ' << (n + 1) / 2 + 1 << ' ' << n << std::endl;
    }
    return 0;
}