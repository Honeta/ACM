#include <stdio.h>
#include <algorithm>
int main() {
    int n, k, a[10001], o[10001], ans[10001] = {0, 0x7fffffff};
    scanf("%d%d", &n, &k);
    for (int i = 2; i <= n; i++) {
        printf("and 1 %d\n\n", i);
        fflush(stdout);
        scanf("%d", &a[i]);
        printf("or 1 %d\n\n", i);
        fflush(stdout);
        scanf("%d", &o[i]);
        ans[1] &= o[i];
    }
    for (int i = 2; i <= n; i++)
        ans[i] = a[i] | (o[i] ^ ans[1]);  
    std::sort(ans + 1, ans + n + 1);
    printf("finish %d\n", ans[k]);
    fflush(stdout);
    return 0;
}