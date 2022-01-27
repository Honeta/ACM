#include <cstdio>
#include <algorithm>

const int N = 100;

int a[N << 1 | 1], sum[N << 1 | 1];
int f_max[N << 1 | 1][N << 1 | 1], f_min[N << 1 | 1][N << 1 | 1];
int ans_max, ans_min = 0x7fffffff;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < (n << 1); i++)
        for (int j = i + 1; j <= (n << 1); j++)
            f_min[i][j] = 1e9;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i + n] = a[i];
    } 
    for (int i = 1; i <= (n << 1); i++)
        sum[i] = sum[i - 1] + a[i];
    for (int l = 2; l <= n; l++)
        for (int i = 1; i < (n << 1 | 1) - l; i++) {
            int j = i + l - 1;
            for (int k = i; k < j; k++) {
                f_max[i][j] = std::max(f_max[i][j], f_max[i][k] + f_max[k + 1][j] + sum[j] - sum[i - 1]);
                f_min[i][j] = std::min(f_min[i][j], f_min[i][k] + f_min[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    for (int i = 0; i <= n; i++) {
        ans_max = std::max(ans_max, f_max[i + 1][i + n]);
        ans_min = std::min(ans_min, f_min[i + 1][i + n]);
    }
    printf("%d\n%d", ans_min, ans_max);            
}