#include <iostream>
#include <vector>
std::vector<int> chain, st, ed;
std::vector<std::vector<int>> g1, g2;
int dfn;
void dfs1(int x, int fa) {
    chain.push_back(x);
    if (fa && g1[x].size() == 1) { 
        /*debug:
        for (auto now : chain)
            std::cout << now << ' ';
        std::cout << std::endl;  
        */
    }
    for (int i = 0; i < g1[x].size(); i++)
        if (g1[x][i] != fa)
            dfs1(g1[x][i], x);
    chain.pop_back();  
}
void dfs2(int x, int fa) {
    st[x] = dfn++;
    for (int i = 0; i < g2[x].size(); i++)
        if (g2[x][i] != fa)
            dfs2(g2[x][i], x);
    ed[x] = dfn++;
}
int main() {
    int t;
    std::cin >> t;
    while (t--) {    
        int n;
        std::cin >> n;
        g1.clear();
        g2.clear();
        st.clear();
        ed.clear();
        g1.resize(n + 1);
        g2.resize(n + 1);   
        st.resize(n + 1);
        ed.resize(n + 1);
        for (int i = 1; i < n; i++) {
            int u, v;
            std::cin >> u >> v;
            g1[u].push_back(v);
            g1[v].push_back(u);
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            std::cin >> u >> v;
            g2[u].push_back(v);
            g2[v].push_back(u);
        }
        dfs1(1, 0);
        dfn = 0;
        dfs2(1, 0);
    }
    return 0;
}