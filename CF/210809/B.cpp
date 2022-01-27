#include <iostream>
#include <algorithm>
#include <map>
int main() {
    long long t, a[100001], b[100001];
    std::map<int, size_t> c;
    std::cin >> t;
    while (t--)
    {
        int n, k;
        std::cin >> n >> k;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
            b[i] = a[i];
        }
        std::sort(b + 1, b + n + 1);
        for (int i = 1; i <= n; i++) 
            c[b[i]] = i;
        for (int i = 1; i <= n; i++) 
            if (i > 1 && c[a[i]] != c[a[i - 1]] + 1)
                ++cnt;
        std::cout << (cnt < k ? "YES" : "NO") << std::endl;
    }
    

    return 0;
}