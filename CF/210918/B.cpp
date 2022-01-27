#include <iostream>
#include <algorithm>
int main() {
    int t, a[100001], b[100001], minn[100001];
    std::cin >> t;
    while (t--) {
        int n, ans = 0x7fffffff;
        std::cin >> n;
        minn[0] = 0x7fffffff;
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
            minn[i] = std::min(minn[i - 1], a[i]);
        }            
        for (int i = 1; i <= n; i++) {
            std::cin >> b[i];
            int l = 1, r = n + 1, pos = 0x7fffffff;
            while (l < r) {
                int mid = l + r >> 1;
                if (minn[mid] < b[i]) {
                    pos = std::min(pos, mid);
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans = std::min(ans, pos - 1 + i - 1);
        }            
        std::cout << ans << std::endl;
    }
    return 0;
}