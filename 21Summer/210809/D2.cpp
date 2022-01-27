#include <iostream>
#include <algorithm>
#include <bitset>
int main() {
    long long ans = 0, n, b[100001], c[100001];
    std::cin >> n;
    for (int i = 2; i <= n; i++) 
        std::cin >> b[i];
    for (int i = 2; i <= n; i++) {
        std::cin >> c[i];
        if (b[i] > c[i]) {
            std::cout << 0;
            return 0;
        }
    }        
    for (int k = 0; k <= b[2]; k++) {
        int now = k;
        bool flag = 1;
        for (int i = 2; i <= n; i++) {
            if (c[i] - now < 0 || ((c[i] - now) | now) != b[i]) {
                flag = 0;
                break;
            }
            now = c[i] - now;
        }
        if (flag) ans++;
    }    
    std::cout << ans;
    return 0;
}