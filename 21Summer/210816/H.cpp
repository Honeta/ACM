#include <iostream>
#include <bitset>
int n, a[1 << 24];
bool vis[1 << 24];
int main() {      
    std::cin >> n;
    for (int i = 0; i < (1 << n); i++) {        
        if (!vis[i]) a[i] = 0, vis[i] = 1;
        std::cout << a[i];
        for (int j = 0; j < n; j++)
            if (!vis[i ^ (1 << j)]) {
                vis[i ^ (1 << j)] = 1;
                a[i ^ (1 << j)] = !a[i];
            }
    }        
    return 0;
}