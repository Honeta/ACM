#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
    char op;
    long long val;
}a[1000005];
long long TP,TN;
bool cmp(node x, node y)
{
    if(x.val==y.val)
    {
        if(y.op=='+') return false;
        if(x.op=='+') return true;
    }
    return x.val<y.val;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].op>>a[i].val;
        if(a[i].op=='+') TP++;
        else TN++;
    }
    sort(a+1,a+1+n,cmp);
    long long L=TP;
    long long tot=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i].op=='+') L--;
        else tot+=L;
    }
    double ans=1.0*tot/(TP*TN);
    printf("%.9lf\n",ans);
}
