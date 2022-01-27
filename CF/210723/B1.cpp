#include <string>
#include <map>
#include <iostream>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::map<char, int> m;
        int ans = 0;
        std::string s;
        std::cin >> s;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
            if (m[s[i]] < 3) ans++;
        }
        std::cout << (ans >> 1) << std::endl;
    }
    return 0;
}