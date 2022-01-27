#include <bits/stdc++.h>
#define maxn 200005
#define mod 4933
using namespace std;
typedef long long LL;
int read()
{
    int f=1,sum=0;char c=getchar();
    while(c<'0' || c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0' && c<='9'){sum=sum*10+c-'0';c=getchar();}
    return sum*f;
}
LL readLL()
{
    LL f=1,sum=0;char c=getchar();
    while(c<'0' || c>'9'){if(c=='-') f=-1LL;c=getchar();}
    while(c>='0' && c<='9'){sum=sum*10+c-'0';c=getchar();}
    return sum*f;
}
int k;
char ans[1000002];
int main()
{
    int T=read();
    while(T--)
    {
        LL n=readLL();
        k=0;
        int num=n/4;
        if(n%4==0)
        {
            k=n;
            for(int i=1;i<=k;i+=4)
            {
                ans[i]=ans[i+3]='1';
                ans[i+1]=ans[i+2]='0';
            }
        }
        if(n%4==1)
        {
            k=num*4+1;
            ans[1]='1';
            for(int i=2;i<=k;i+=4)
            {
                ans[i]=ans[i+3]='1';
                ans[i+1]=ans[i+2]='0';
            }
        }
        if(n%4==2)
        {
            k=n+2;
            ans[1]='0';
            ans[2]='0';
            ans[3]='0';
            ans[4]='1';
            for(int i=5;i<=k;i+=4)
            {
                ans[i]=ans[i+3]='1';
                ans[i+1]=ans[i+2]='0';
            }
        }
        if(n%4==3)
        {
            k=num*4+2;
            ans[1]='0';
            ans[2]='1';
            for(int i=3;i<=k;i+=4)
            {
                ans[i]=ans[i+3]='1';
                ans[i+1]=ans[i+2]='0';
            }
        }
        printf("%d\n",k);
        for(int i=1;i<=k;i++)
        putchar(ans[i]);
        puts("");
    }
    return 0;
}