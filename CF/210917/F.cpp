#include <iostream>
#include <algorithm>
char a[501][501];
int b[501][501], c[501][501], tot[501][501];
int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 'X') {
                int cnt = 0;
                if (a[i - 1][j] == '.') ++cnt;
                if (a[i + 1][j] == '.') ++cnt;
                if (a[i][j - 1] == '.') ++cnt;
                if (a[i][j + 1] == '.') ++cnt; 
                b[i][j] = c[i][j] = cnt / 2 * 5;
                tot[i][j] = cnt;
            }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == '.') {
                int min = 10000, ttot = 1000;
                if (a[i][j + 1] == 'X') min = std::min(min, b[i][j + 1]), ttot = std::min(ttot, tot[i][j + 1]);
                if (a[i][j - 1] == 'X') min = std::min(min, b[i][j - 1]), ttot = std::min(ttot, tot[i][j - 1]);
                if (a[i + 1][j] == 'X') min = std::min(min, b[i + 1][j]), ttot = std::min(ttot, tot[i + 1][j]);
                if (a[i - 1][j] == 'X') min = std::min(min, b[i - 1][j]), ttot = std::min(ttot, tot[i - 1][j]);
                if (min == 0) {
                    std::cout << "NO";
                    exit(0);
                }
                else if (min > 4 || (min == 4 && ttot == 1)) {
                    c[i][j] = 4;
                    if (a[i][j + 1] == 'X') b[i][j + 1] -= 4, --tot[i][j + 1];
                    if (a[i][j - 1] == 'X') b[i][j - 1] -= 4, --tot[i][j - 1];
                    if (a[i + 1][j] == 'X') b[i + 1][j] -= 4, --tot[i + 1][j];
                    if (a[i - 1][j] == 'X') b[i - 1][j] -= 4, --tot[i - 1][j];
                }                    
                else {
                    c[i][j] = 1;
                    if (a[i][j + 1] == 'X') b[i][j + 1] -= 1, --tot[i][j + 1];
                    if (a[i][j - 1] == 'X') b[i][j - 1] -= 1, --tot[i][j - 1];
                    if (a[i + 1][j] == 'X') b[i + 1][j] -= 1, --tot[i + 1][j];
                    if (a[i - 1][j] == 'X') b[i - 1][j] -= 1, --tot[i - 1][j];
                }
            }/*
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (b[i][j]) {
                std::cout << "NO";
                exit(0);
            }*/
    std::cout << "YES" << std::endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            std::cout << b[i][j] << ' ';
        std::cout << std::endl;
    }
        
    return 0;
}