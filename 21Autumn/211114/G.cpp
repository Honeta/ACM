#include <cstdio>
#include <algorithm>
int a[1001];
long long ans;
int main() {
    int n, k;
    scanf("%d%d", &n ,&k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= k; i++)
        ans += a[n - i + 1];
    printf("%lld", ans);
}