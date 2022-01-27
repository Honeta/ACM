#include <iostream>
#include <cstdio>
#include <iomanip> 
#include <queue>
#include <utility>
int main() {
    int n, m, a[501][501];
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%1d", &a[i][j]);
    int q;
    std::cin >> q;
    while (q--) {
        int t, x1, y1, x2, y2;
        std::cin >> t >> x1 >> y1 >> x2 >> y2;
        if (t == 1) {            
            if (y1 != y2) 
                std::cout << "no" << std::endl;
            else {
                bool flag = 1;
                for (int i = x1; i <= x2; i++)
                    if (a[i][y1]) {
                        flag = 0;
                        break;
                    }
                if (flag) std::cout << "yes" << std::endl;
                else std::cout << "no" << std::endl;
            }           
        } else if (t == 2) {            
            if (x1 != x2) 
                std::cout << "no" << std::endl;
            else {
                bool flag = 1;
                for (int i = y1; i <= y2; i++)
                    if (a[x1][i]) {
                        flag = 0;
                        break;
                    }
                if (flag) std::cout << "yes" << std::endl;
                else std::cout << "no" << std::endl;
            }           
        } else {
            bool flag = 0;
            std::queue<std::pair<int, int>> q;
            q.push({x1, y1});
            while (q.size()) {
                auto now = q.front();
                q.pop();
                if (now.first == x2 && now.second == y2) {
                    flag = 1;
                    break;
                }
                if (!a[now.first][now.second + 1])
                    q.push({now.first, now.second + 1});
                if (!a[now.first + 1][now.second])
                    q.push({now.first + 1, now.second});
            }
            if (flag) std::cout << "yes" << std::endl;
            else std::cout << "no" << std::endl;
        }
    }
    return 0;
}