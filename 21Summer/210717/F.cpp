#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::vector<int> v;
    for(int i = 0; i <= 99; i++) {
        if (i < 10 && i % 3 == 0)
            v.push_back(i);
        else if (i >= 10) {
            int l = i / 10;
            int r = i % 10;
            if (l % 3 == 1 && r % 3 == 0)
                v.push_back(i);
            else if (l % 3 == 1 && r % 3 == 2)
                v.push_back(i);
            else if (l % 3 == 2 && r % 3 == 0)
                v.push_back(i);
            else if (l % 3 == 2 && r % 3 == 1)
                v.push_back(i);
            else if (l % 3 == 0)
                v.push_back(i);
        }
    }
    int t;
    std::cin >> t;
    while (t--) {
        long long l, r;
        std::cin >> l >> r;
        --l;
        long long ans1, ans2;
        if (l < 100)
            ans1 = std::upper_bound(v.begin(), v.end(), l) - v.begin();
        else
            ans1 = v.size() + l - 99;
        if (r < 100)
            ans2 = std::upper_bound(v.begin(), v.end(), r) - v.begin(); 
        else
            ans2 = v.size() + r - 99;
        std::cout << ans2 - ans1 << std::endl;
    }
    return 0;
}