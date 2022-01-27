#include <iostream>
#include <string>
#include <cstring>
int sum[26][500000];
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s, ans1, ans2;
        std::cin >> s;
        memset(sum, 0, sizeof(sum));
        bool done[26];
        int tot = 0;
        for (int i = 0; i < s.size(); i++)
            for (int k = 0; k < 26; k++) {
                sum[k][i] = s[i] - 'a' == k ? sum[k][i - 1] + 1 : sum[k][i - 1];
                if (!done[s[i]]) {
                    done[s[i]] = 1;
                    tot++;
                }
            }
                
        bool vis[26];
        int a[26];
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < s.size(); i++) {
            char eq = '\0';
            int cnt[30];
            memset(cnt, 0, sizeof(cnt));
            for (int k = 0; k < 26; k++)
                if (!vis[k] && sum[k][i] && sum[k][i] == sum[k][s.size() - 1]) {
                    eq = k + 'a';
                }                    
                else if (ans1.empty() && sum[k][i] && sum[k][s.size() - 1] % sum[k][i] == 0)
                    cnt[sum[k][s.size() - 1] / sum[k][i]]++;
            if (ans1.empty()) {
                bool flag = 1;
                for (int i = 1; i < tot; i++)
                    if (cnt[i] != 1) {
                        flag = 0;
                        break;
                    }
                if (eq != '\0' && flag) {
                    ans1 = s.substr(0, i + 1);
                    vis[eq - 'a'] = 1;
                    ans2.push_back(eq);
                    continue;
                }
            }            
            if (!ans1.empty() && eq != '\0') {
                vis[eq - 'a'] = 1;
                ans2.push_back(eq);
            }
        }
        std::cout << ans1 << ' ' << ans2 << std::endl;
    }
    return 0;
}