#include <iostream>
#include <string>
int a[26];
int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int ans = 0;
        std::string s, t;
        std::cin >> s >> t;
        for (int i = 0; i < 26; i++)
            a[s[i] - 'a'] = i;
        for (int i = 1; i < t.size(); i++)
            ans += abs(a[t[i] - 'a'] - a[t[i - 1] - 'a']);
        std::cout << ans << std::endl;
    }
}