#include <iostream>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <vector>
int func(long long n, long long k) {
    int ans = 0;
    std::vector<int> a, b;
    while (n) {
        a.push_back(n % 10);
        n /= 10;
    }
    while (k) {
        b.push_back(k % 10);
        k /= 10;
    }
    std::reverse(a.begin(), a.end());  
    std::reverse(b.begin(), b.end());      
    int i = 0;
    for (int j = 0; j < b.size(); j++) {
        for (; i < a.size(); i++)    
            if (a[i] == b[j]) {
                ans++;
                break;
            }
        i++;
        if (ans != j + 1) break;
    }
    return ans;
}
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        if (std::bitset<50>(n).count() == 1) {
            std::cout << 0 << std::endl;
            continue;
        }
        int ans = 1e9, nbak = n;
        int d1 = 0;
        while (nbak) {
            nbak /= 10;
            ++d1;
        }
        for (int i = 0; i <= 61; i++) {
            long long k = 1LL << i;            
            int d3 = func(n, k);
            int d2 = 0;
            while (k) {
                k /= 10;
                ++d2;
            }
            ans = std::min(ans, d1 - d3 + d2 - d3);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}