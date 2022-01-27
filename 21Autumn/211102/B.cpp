#include <iostream>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long x, n;
        std::cin >> x >> n;
        long long ans;
        if (x % 2) {
            switch (n % 4) {
                case 0: ans = x;break;
                case 1: ans = x + n;break;
                case 2: ans = x - 1;break;
                case 3: ans = x - 1 - n;break;
            }
        } else {
            switch (n % 4) {
                case 0: ans = x;break;
                case 1: ans = x - n;break;
                case 2: ans = x + 1;break;
                case 3: ans = x + 1 + n;break;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}