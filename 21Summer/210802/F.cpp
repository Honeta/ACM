#include <iostream>
#include <algorithm>
#include <queue>
int main() {
    int n, m;
    long long maxt = 0, avet = 0, t[100001];   
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> t[i];
        maxt = std::max(maxt, t[i]);
        avet += t[i];
    }
    (avet += m - 1) /= m;
    if (maxt < avet) maxt = avet;
    int now = 1;
    long long nowsum = 0;
    for (int i = 1; i <= n; i++) {
        if (nowsum + t[i] <= maxt) {
            std::cout << "1 " << now << ' ' << nowsum << ' ' << nowsum + t[i] << std::endl;
            nowsum += t[i];
            if (nowsum == maxt) {
                now++;
                nowsum = 0;
            }
        } else {
            std::cout << "2 " << now + 1 << ' ' << 0 << ' ' << nowsum + t[i] - maxt << ' '
                      << now << ' ' << nowsum << ' ' << maxt << std::endl;
            now++;
            nowsum = nowsum + t[i] - maxt;            
        }
    }
    return 0;
}