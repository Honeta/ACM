#include <iostream>
#include <string>
int n, sum1[100001], sum2[100001];
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long ans = 0;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        for (int i = 1; i <= n; i++) {
            sum1[i] = sum1[i - 1];
            sum2[i] = sum2[i - 1];
            if (s[i - 1] == 'L') sum1[i]--;
            else if (s[i - 1] == 'R') sum1[i]++;
            else if (s[i - 1] == 'U') sum2[i]++;
            else sum2[i]--;
        }
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                if (sum2[j] == sum2[i - 1] && sum1[j] == sum1[i - 1])
                    ++ans;
        std::cout << ans << std::endl;
    }
    return 0;
}