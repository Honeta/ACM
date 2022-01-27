#include <iostream>
#include <algorithm>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        unsigned int n, ans = 0, a[101];
        std::cin >> n;
        for (int i = 1; i <= n; i++) 
            std::cin >> a[i];            
        for (int i = 30; i >= 0; i--) {
            bool flag = 1;
            for (int j = 1; j <= n; j++)
                if (((1u << i) & a[j]) == 0) {
                    flag = 0;
                    break;
                }
            if (flag) {
                ans += (1 << i);
            }
        }
        std::cout << ans << std::endl;                
    }
    return 0;
}