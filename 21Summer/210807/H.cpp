#include <iostream>
#include <cmath>
#include <map>
int n, a[1000001], cnt[1000001];
long long ans;
int main() {  
    std::cin >> n;  
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= sqrt(a[i]); j++) 
            if (cnt[j] && a[i] % j == 0 && cnt[a[i]/j]) {
                if (j * j == a[i])
                    ans += cnt[j] * cnt[a[i]/j];
                else
                    ans += cnt[j] * cnt[a[i]/j] * 2;
            }
                
    std::cout << ans;
    return 0;
}