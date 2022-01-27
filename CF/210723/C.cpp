#include <iostream>
#include <vector>
#include <string>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::string> v(n);
        std::vector<std::vector<int>> cnt(n);
        for (int i = 0; i < n; i++) {            
            cnt[i].resize(5);
            std::cin >> v[i];
            for (int j = 0; j < v[i].size(); j++)
                cnt[i][v[i][j] - 'a']++;
        }
    }
    return 0;
}