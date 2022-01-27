#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+1;
const int MAXM = 30;
int n;
char s[MAXN];
set<string>ans;
int vis[MAXM];
int trans(char x) {
    return x - 'a';
}
char letter(int x) {
    return x + 'a';
}

int main() {
    scanf("%d",&n);
    scanf("%s", s+1);
    for(int i = 1; i <= n ; i++) {
        for(int j = 0; j < 30; j++) {
            vis[j] = -1;
        }
        int cnt = 0;
        for(int j = i; j >= 1; j--) {
            if(vis[trans(s[j])] == -1) {
                vis[trans(s[j])] = cnt++;
            }
        }
        string temp{};
        for(int j = 1; j <= i; j++) {
            temp += letter(vis[trans(s[j])]);
        }
        //cout << temp << endl;
        ans.insert(temp);
    }
    set<string>::iterator it;
    it = ans.end(); it--;
    cout << *it << endl;
}