#include <iostream>
#include <stdio.h>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, ans = 0;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            int temp;
            scanf("%1d", &temp);
            ans += temp;
            if (temp && (i != n))
                ans++;
        }            
        std::cout << ans << std::endl;
    }
    return 0;
}