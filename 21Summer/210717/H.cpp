#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
int main() {
    std::vector<long long> v;
    int n;
    long long sum = 0;
    int maxx = 0;
    std::cin >> n;
    int a[500001];
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        sum += a[i];
        maxx = std::max(maxx, a[i]); 
    }
    sum -= n * (n-1) / 2;
    for (int i = 1; i <= sqrt(sum); i++)
        if (sum % i == 0) {
            if (i >= n && i <= maxx)
                v.push_back(i);
            if (sum / i >= n && sum / i <= maxx)
                v.push_back(sum / i);
        }
    if (v.empty()) v.push_back(n);
    std::sort(v.begin(), v.end());        
    for (int i = 0; i < v.size(); i++) {
        std::set<int> s;
        for (int j = 1; j <= n; j++) {
            s.insert(a[j] % v[i]);
            if (s.size() < j)
                break;
            if (j == n) {
                std::cout << v[i];
                return 0;
            }
        }
    }
}