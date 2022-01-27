#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[1000005],b[1000005];
long long sum1,sum2;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++)
    {
        sum1+=a[i];
        sum2+=b[i];
        if(sum1==sum2) ans++;
    }
    printf("%d\n",ans);
}
