#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int d[505],k[505],c[505];
int Day[300005],tot;
long long dp[300005];
int main()
{
    scanf("%d%d%d",&n,&m,&r);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&d[i],&k[i],&c[i]);
    for(int i=1;i<=m;i++)
    {
        int p,q;
        scanf("%d%d",&p,&q);
        while(q--) Day[++tot]=p;
    }
    sort(Day+1,Day+1+tot);
    for(int j=1;j<=tot;j++)
    {
        dp[j]=dp[j-1]+r;
        for(int i=1;i<=n;i++)
        {
            int x=max(1,j-k[i]+1);
            if(Day[x]+d[i]-1<Day[j])
            {
                x=lower_bound(Day+x, Day+j+1, Day[j]-d[i]+1)-Day;
                while(Day[x]+d[i]-1<Day[j]) x++;
            }
            dp[j]=min(dp[j],dp[x-1]+c[i]);
        }
    }
    printf("%lld\n",dp[tot]);
}