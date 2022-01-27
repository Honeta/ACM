#include <iostream>
#include <string>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        int sum0 = 0, sum1 = 0;
        for (int i = 0; i < s.size(); ++i)
            if (i & 1) sum1 = sum1 * 10 + (s[i] - '0');
            else sum0 = sum0 * 10 + (s[i] - '0');
        std::cout << (sum0 + 1) * (sum1 + 1) - 2 << std::endl;
    }
    return 0;
}