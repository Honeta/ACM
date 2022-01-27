#include <iostream>
#include <cstdio>
#include <vector>
std::vector<int> e, g, vis, pa;
std::vector<std::vector<int>> v;
bool dfs(int x) {
    for(int i = 0; i < v[x].size(); i++){        //遍历所有的男生编号 
        if(vis[v[x][i]] == 0){    //如果有连线且boy[i]没有被本次查找遍历过 
            vis[v[x][i]] = 1;                        //假设i号boy被遍历到了 
            if(!pa[v[x][i]] || dfs(pa[v[x][i]])){    //如果boy[i]没有被占用或者能把占用boy[i]的人换一个连线，短路原则如果没有被占用则不会执行后面的部分 
                pa[v[x][i]] = x;                    //这一步的作用是执意要将boy[i]匹配给x(尽可能给腾位置出来，因为她可能占了别的女生相匹配的男生)        
                return true;
            } 
        }
    }
    return false;
}
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, ans = 0;
        std::cin >> n;
        pa.clear();
        v.clear();        
        e.resize(n);
        g.resize(n);
        v.resize(n);
        pa.resize(n);
        for (int i = 0; i < n; i++)
            scanf("%1d", &e[i]);
        for (int i = 0; i < n; i++) {
            scanf("%1d", &g[i]);
            if (g[i] && !e[i])
                ans++;
            else {
                if (i > 0 && g[i] && e[i - 1])
                v[i - 1].push_back(i);
                if (i < n - 1 && g[i] && e[i + 1])
                v[i + 1].push_back(i);
            }
        }
        for(int i = 0; i < n; i++){
             vis.clear();
             vis.resize(n);
                      //vis每一次都将所有的男生编号都标记为没遍历过，注意区分vis[]和boy[]数组功能的区别 
             if(dfs(i)) ans++;                    //如果能直接相连或别人腾出位置总数+1 
         }
         std::cout << ans << std::endl;
    }
}