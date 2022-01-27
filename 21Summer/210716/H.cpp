#include <iostream>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        unsigned long long l, r, ans1, ans2, ans;
        std::cin >> l >> r;
        l--;
        if (l % 4ull == 1ull) ans1 = 1ull;
        else if (l % 4ull == 2ull) ans1 = l + 1ull;
        else if (l % 4ull == 3ull) ans1 = 0ull;
        else ans1 = l;
        if (r % 4ull == 1ull) ans2 = 1ull;
        else if (r % 4ull == 2ull) ans2 = r + 1ull;
        else if (r % 4ull == 3ull) ans2 = 0ull;
        else ans2 = r;
        ans = ans1 ^ ans2;
        std::cout << ans << std::endl;
    }
    return 0;
}