#include <iostream>
int main() {
    int t, a[100000], ans[100000], sum = 0;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
            sum += a[i];
        }            
        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j < n; j++) 
                if (i ^ j > i)
                    ans[i] += a[j];
    }
    return 0;
}