#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
struct edge{int from, to, w;};
bool cmp(edge x, edge y) {return x.w < y.w;}
std::vector<edge> v;
long long ans; 
int w[5001 * 5001], r[10001];
int getfa(int x) {return r[x] == x ? r[x] : getfa(r[r[r[x]]]);}
void merge(int x, int y) {r[getfa(x)] = getfa(y);}
int main() {
    int n, m, a, b, c, d, p;    
    std::cin >> n >> m >> a >> b >> c >> d >> p;
    w[0] = a;
    for (int i = 1; i <= n + m; i++)
        r[i] = i;
    for (int i = 1; i <= n * m; i++)
        w[i] = (w[i-1] * w[i-1] % p * b % p + w[i-1] * c % p + d) % p;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            v.push_back({i, j + n, w[m * (i - 1) + j]});
    long long ans = 0;
    std::sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        if (getfa(v[i].from) == getfa(v[i].to)) continue;
        merge(v[i].from, v[i].to);
        ans += v[i].w;
    }   
    std::cout << ans;
    return 0;
}