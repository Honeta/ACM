#include <iostream>
#include <algorithm>
int a[200001];
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        long long ans = -0x7fffffff; 
        std::cin >> n;
        for (int i = 1; i <= n; i++)
            std::cin >> a[i];
        std::sort(a + 1, a + n + 1);
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            ans = std::max(ans, a[i] - sum);
            sum += a[i] - sum;
        }            
        std::cout << ans << std::endl;
    }
}