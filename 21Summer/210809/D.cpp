#include <iostream>
#include <algorithm>
#include <bitset>
int main() {
    long long ans = 1, n, b[100001], c[100001];
    std::cin >> n;
    for (int i = 2; i <= n; i++) 
        std::cin >> b[i];
    for (int i = 2; i <= n; i++) {
        std::cin >> c[i];
        if (b[i] > c[i]) {
            std::cout << 0;
            return 0;
        }
        b[i] -= c[i] - b[i];
    }
    for (int k = 0; k <= 32; k++) {
        int cnt = 0; 
        for (int j = 0; j <= 1; j++) {
            int now = j;
            bool flag = 1;
            for (int i = 2; i <= n; i++) {
                if (now > ((b[i] & (1LL << k)) > 0)) {
                    flag = 0;
                    break;
                }
                now ^= ((b[i] & (1LL << k)) > 0);
            }
            if (flag) cnt++;
        }
        ans *= cnt;
    }
    std::cout << ans;
    return 0;
}