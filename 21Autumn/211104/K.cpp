#include <iostream>
#include <string>
int main() {
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 1; i <= n+1; i++) {        
        std::string s;
        std::getline(std::cin, s);
        for (auto c : s) {
            if (c == '-') ++ans;
        }
    }
    std::cout << ans << std::endl;
}