#include <iostream>
#include <algorithm>
#include <stdio.h>
int main() {
    long long t, a[100001], sum[100001];
    std::cin >> t;
    while (t--)
    {
        double ans = -1e10;
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; i++)
            std::cin >> a[i];
        std::sort(a + 1, a + n + 1); 
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + a[i];
        for (int i = 1; i < n; i++) {
            ans = std::max(ans, sum[i] * 1.0 / i + (sum[n] - sum[i]) * 1.0 / (n - i));
        }
        printf("%.9lf\n", ans);
    }
    

    return 0;
}