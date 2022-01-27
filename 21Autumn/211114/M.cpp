#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
const int MAXM = 20;
const int MAXL = 1<<20;
typedef long long ll;
int num[MAXN];
ll cnt[MAXL];
int n, m;
ll k;
ll f[MAXL];

void FWT_xor(ll *a,int opt, int N)
{
    for(int i=1;i<N;i<<=1)
        for(int p=i<<1,j=0;j<N;j+=p)
            for(int k=0;k<i;++k)
            {
                ll X=a[j+k],Y=a[i+j+k];
                a[j+k]=(X+Y);a[i+j+k]=(X-Y);
                if(opt==-1)a[j+k]=1ll*a[j+k]/2,a[i+j+k]=1ll*a[i+j+k]/2;
            }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    int len = 1 << m;
    string s;
    for(int i = 0; i < n; i ++) {
        cin  >> s;
        int t = 0;
        for(int j = 0; j < m; j++) {
            t = (t<<1) + (s[j]=='A');
        }
        num[i] = t;
        cnt[num[i]] ++;
    }

    FWT_xor(cnt, 1, len);
    for(int i = 0; i < len; i++) {
        cnt[i] = cnt[i] * cnt[i];
    }
    FWT_xor(cnt, -1, len);
    cnt[0] -= n;
    
    int mask = len-1;
    for(int i = 0; i < len; i++) {
        f[i] = cnt[i^mask] / 2;
    }

    for(int i = 0; i < m; i++) {
        for(int s = 0; s < len; s++)  {
            if(s&(1<<i))f[s^(1<<i)] += f[s];
        }
    }
    int ans = 0;
    for(int i = 0; i < len; i++) {
        if(1ll*n*(n-1)/2 - f[i] >= k) ans++;
    }
    cout << ans << endl;
    return 0;
}