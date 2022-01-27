#include <iostream>
#include <vector>
std::vector<int> ans;
int main() {
    int t;    
    int cnt = 1;
    while (ans.size() <= 1000) {
        if (cnt % 3 != 0 && cnt % 10 != 3)
            ans.push_back(cnt);
        ++cnt;
    }        
    std::cin >> t;
    while (t--) {
        int k;
        std::cin >> k;
        std::cout << ans[k - 1] << std::endl;
    }
    return 0;
}