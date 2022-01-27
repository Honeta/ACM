#include <iostream>
#include <string>
const int MOD = 1e9 + 7;
int d[5001][5001], f[5001][5001];
long long ans;
int main() {   
    std::string s1, s2;
    std::cin >> s1 >> s2;
    s1.insert(s1.begin(), '\0');
    s2.insert(s2.begin(), '\0');
    for (int i = 1; i < s1.size(); i++)
        for (int j = 1; j < s2.size(); j++)
            f[i][j] = (1LL + f[i][j - 1] + f[i - 1][j]) % MOD;
    for (int i = 1; i < s1.size(); i++)
        for (int j = 1; j < s2.size(); j++) {
            if (s1[i] == s2[j]) {
                d[i][j] = (1LL + (d[i][j - 1] + d[i - 1][j]) % MOD) % MOD;
            } else {
                d[i][j] = (1LL * d[i][j - 1] + d[i - 1][j] + MOD - d[i - 1][j - 1]) % MOD;
                if (s1[i] < s2[j]) {
                    int m = s1.size() - 1 - i, n = s2.size() - 1 - j;
                    (ans += (1LL + d[i - 1][j - 1]) % MOD * (f[m][n] + 1LL) % MOD) %= MOD;                    
                }
            }         
        }
    std::cout << ans;
    return 0;
}