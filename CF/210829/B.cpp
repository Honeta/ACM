#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> v(n);
        int cntodd = 0, cnteven = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> v[i];
            if (v[i] & 1) cntodd++;
            else cnteven++;
        }
        if (((n & 1) == 0) && cntodd * 2 != n) {
            std::cout << -1 << std::endl;
            continue;
        }
        if ((n & 1) && std::min(cntodd, cnteven) != n / 2) {
            std::cout << -1 << std::endl;
            continue;
        }
        if ((n & 1) && cntodd > cnteven) {
            int k = 0;
            long long ans = 0;
            for (int i = 0; i < n; i++) {
                if (v[i] & 1) {
                    ans += std::abs(i - k);
                    k += 2;
                }
            }
            std::cout << ans << std::endl;
            continue;
        }
        if ((n & 1) && cntodd < cnteven) {
            int k = 0;
            long long ans = 0;
            for (int i = 0; i < n; i++) {
                if ((v[i] & 1) == 0) {
                    ans += std::abs(i - k);
                    k += 2;
                }
            }
            std::cout << ans << std::endl;
            continue;
        }
        long long ans1 = 0, ans2 = 0, k = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] & 1) {
                ans1 += std::abs(i - k);
                ans2 += std::abs(i - (k + 1));
                k += 2;
            }
        }
        std::cout << std::min(ans1, ans2) << std::endl;
    }
    return 0;
}