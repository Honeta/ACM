#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
bool nprime[100001] = {1, 1};
std::vector<int> p, np = {1};
void pre() {
    for(int  i = 2 ; i < 100000 ; i ++)       
       	{            
		if (nprime[i])               
	 		np.push_back(i); 
        else
            p.push_back(i);  
        for (auto x : p) {
            if (i * x >= 100000) break;
            nprime[x * i] = 1;
            if (i % x == 0)
                break;
        }   
	} 
}
int lcs(std::vector<int> v1, std::vector<int> v2) {
    int f[51][51];
    memset(f, 0, sizeof(f));
    int i,j;
    for(i = 1; i <= v1.size(); i++)
    {
        for(j = 1; j <= v2.size(); j++)
        {
            if (v1[i - 1] == v2[j - 1])
                f[i][j] = f[i - 1][j - 1] + 1;
            else
                f[i][j] = std::max(f[i][j - 1], f[i - 1][j]);
        }
    }
    return f[v1.size()][v2.size()];
}
int main() {
    pre();
    int t;
    std::cin >> t;
    while (t--) {
        int k;
        std::vector<int> v1;
        std::cin >> k;
        for (int i = 0; i < k; i++) {
            int temp;
            scanf("%1d", &temp);
            v1.push_back(temp);
        }
        for (auto xx : np) {
            std::vector<int> v2;
            int x = xx;
            while (x) {
                v2.push_back(x % 10);
                x /= 10;
            }
            std::reverse(v2.begin(), v2.end());
            if (lcs(v1, v2) != v2.size()) continue;
            std::cout << v2.size() << std::endl << xx << std::endl;
            break;
        }
    }
    return 0;
}