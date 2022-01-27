#include <iostream>
#include <algorithm>
#include <vector>
std::vector<int> v;
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int ans = 0;        
        v.resize(n + 1);
        for (int i = 1; i <= n; i++)
            std::cin >> v[i];
        for (; ; ans++) {
            int i;
            for (i = 1; i <= n; i++) 
                if (v[i] != i)
                    break;
            if (i > n) break;
            for (int i = 0, j = (ans & 1) + 1; i <= (n - 3 >> 1); i++, j += 2)
                if (v[j] > v[j + 1])
                    std::swap(v[j], v[j + 1]);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}