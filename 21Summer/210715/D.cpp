#include <iostream>
#include <cmath>
#include <algorithm>
int main() {
    long long n, m, a, b, ans = 0;
    std::cin >> n >> m >> a >> b;
    for (long long c = n - a - b - std::min(a,b); c <= n - a - b; ++c) {
        if (floor((c * 1.0 / a + m) * a * b / (a + b)) - ceil((c * 1.0 / a - m) * a * b / (a + b) * b) >= 0)
        //std::cout << c << ' ' << (c * 1.0 / a + m) * a / (a + b) << ' ' << (c * 1.0 / a - m) * a / (a + b) << std::endl;
        ans += 1 + floor((c * 1.0 / a + m) * a * b / (a + b)) - ceil((c * 1.0 / a - m) * a * b / (a + b) * b);
    }
    std::cout << ans;
    return 0;
}