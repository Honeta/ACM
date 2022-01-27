#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int a, b;
        std::cin >> a >> b;
        std::vector<int> v;
        if ((a + b) & 1) {
            int mid = a + b >> 1;
            int base1 = std::abs(a - mid), base2 = std::abs(a - (mid + 1));
            int cnt = base1;
            while (cnt <= mid) {
                v.push_back(cnt);
                if (cnt != mid)
                    v.push_back(a + b - cnt);
                cnt += 2;
            }
            cnt = base2;
            while (cnt <= mid + 1) {
                v.push_back(cnt);
                if (cnt != mid + 1)
                    v.push_back(a + b - cnt);
                cnt += 2;
            }
        } else {
            int mid = a + b >> 1;
            int base = std::abs(a - mid);
            int cnt = base;
            while (cnt <= mid) {
                v.push_back(cnt);
                if (cnt != mid)
                    v.push_back(a + b - cnt);
                cnt += 2;
            }
        }        
        std::cout << v.size() << std::endl;
        std::sort(v.begin(), v.end());
        for (auto x : v)
            std::cout << x << ' ';
        std::cout << std::endl;
    }
    return 0;
}