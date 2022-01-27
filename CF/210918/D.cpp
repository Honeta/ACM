#include <iostream>
#include <vector>
void solve(std::vector<int> v, int st) {
    int n = v.size();
    for (int i = 1; i <= n - 2; i += 2)
        std::cout << st + i << ' ';
    for (int i = n - 4; i >= 1; i -= 2)
        std::cout << st + i << ' ';
}
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> v(n + 1), xor_sum(n + 1);
        for (int i = 1; i <= n; i++) {
            std::cin >> v[i];
            xor_sum[i] = xor_sum[i - 1] ^ v[i];
        }
        if (xor_sum[n]) {
            std::cout << "NO" << std::endl;
            continue;
        }
        if (n & 1) {
            std::cout << "YES" << std::endl << (n - 2 + n - 4 + 2 >> 1) << std::endl;
            solve(std::vector<int>(v.begin() + 1, v.end()), 0);
            std::cout << std::endl;
        } else {
            bool flag = 0;
            for (int i = 1; i <= n - 1; i += 2)
                if (xor_sum[i] == 0) {
                    flag = 1;
                    if (i == 1) {
                        std::cout << "YES" << std::endl << (n - 3 + n - 5 + 2 >> 1) << std::endl;
                        solve(std::vector<int>(v.begin() + i + 1, v.end()), i);
                    } else if (i == n - 1) {
                        std::cout << "YES" << std::endl << (n - 3 + n - 5 + 2 >> 1) << std::endl;
                        solve(std::vector<int>(v.begin() + 1, v.begin() + i + 1), 0);
                    } else {
                        std::cout << "YES" << std::endl << (n - 2 + n - 4 + 2 >> 1) << std::endl;
                        solve(std::vector<int>(v.begin() + 1, v.begin() + i + 1), 0);
                        solve(std::vector<int>(v.begin() + i + 1, v.end()), i);
                    }
                    std::cout << std::endl;
                    break;
                }
            if (!flag) {
                std::cout << "NO" << std::endl;
            }
        }            
    }
    return 0;
}