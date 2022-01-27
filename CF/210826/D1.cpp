#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, q;
        std::cin >> n >> q;
        std::string s;
        std::cin >> s;
        int sum1[30001], sum2[30001];
        sum1[0] = sum2[0] = 0;
        for (int i = 1; i <= n; i++) {
            sum1[i] = sum1[i - 1];
            sum2[i] = sum2[i - 1];
            s[i - 1] == '+' ? sum1[i] += pow(-1, (i + 1) & 1) : sum2[i] -= pow(-1, (i + 1) & 1);
        }
            
        while (q--) {
            int l, r;
            std::cin >> l >> r;
            std::cout << sum1[r] - sum1[l - 1] << ' ' << sum2[r] - sum2[l - 1] << std::endl;
        }
    }
    return 0;
}