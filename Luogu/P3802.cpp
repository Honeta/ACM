#include <iostream>
#include <iomanip>
int main() {
    int a[8], sum = 0;
    for (int i = 1; i <= 7; i++) {
        std::cin >> a[i];
        if (!a[i]) {
            std::cout << "0.000";
            return 0;
        }
        sum += a[i];
    }
    double ans = 1.0 * 2 * 3 * 4 * 5 * 6 * 7 * (sum - 6);
    for (int i = 1; i <= 7; i++)
        ans *= a[i] * 1.0 / (sum - i + 1);
    std::cout << std::fixed << std::setprecision(3) << ans;
    return 0;
}