#include <bits/stdc++.h>
using namespace std;
string a,b;
int A[4],B[4];
int cal(int sta)
{
    int up[4]={0,0,0,0},down[4]={0,0,0,0}, ans = 0;
    for(int i=0;i<4;i++)
    {
        int m=B[i]-A[i];
        //cout<<m<<endl;
        if(sta&(1<<(3 - i)))
        {
            up[i]=(m>0)?10-m:-m;
            if (i && up[i - 1]) {
                ans += up[i] > up[i - 1] ? up[i] - up[i - 1] : 0;
            } else {
                ans += up[i];
            }
        }
        else {
            down[i]=(m>=0)?m:10+m;
            if (i && down[i - 1])
                ans += down[i] > down[i - 1] ? down[i] - down[i - 1] : 0;
            else    
                ans += down[i];
        }
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        cin>>a>>b;
        int ans=114514;
        for(int i=0;i<4;i++) A[i]=a[i]-'0',B[i]=b[i]-'0';
        for(int sta=0;sta<16;sta++)
        {
            ans=min(ans,cal(sta));
        }
        cout<<ans<<endl;
    }
}