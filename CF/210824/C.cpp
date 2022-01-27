#include <iostream>
#include <vector>
#include <algorithm>
struct cave {int k, maxx = 0;};
bool cmp(cave x, cave y) {
    return x.maxx < y.maxx;
}
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<cave> v(n);
        for (int i = 0; i < n; i++) {
            std::cin >> v[i].k;
            for (int j = 0; j < v[i].k; j++) {
                int temp;
                std::cin >> temp;
                v[i].maxx = std::max(v[i].maxx, temp + 1 - j);
            }
        }
        std::sort(v.begin(), v.end(), cmp);
        int ans = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            ans = std::max(ans, v[i].maxx - sum);
            sum += v[i].k;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}