#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
int main()
{
    int n,k,r=-2e9-1,l=0,ans=2e9+10;
    std::cin>>n>>k;
    std::vector<int> a,f;
    a.resize(n+1);
    f.resize(k+1);
    for(int i=1;i<=n;i++)
    {
        std::cin>>a[i];
        r=std::max(r,abs(a[i]-a[i-1]));
        l=std::min(l,abs(a[i]-a[i-1]));
    }
    while(l<r)
    {
        int mid=l+r>>1,cnt1=0,cnt2=0;
        std::vector<int> b=a,c=a;
        for(int i=2;i<=n;i++)
        {
            if(abs(b[i]-b[i-1])>mid)
            {
                ++cnt1;
                b[i]=b[i]>b[i-1]?b[i-1]+mid:b[i-1]-mid;
            }
            if(abs(c[i]-c[i-1])>mid)
            {
                ++cnt2;
                c[i]=c[i]>c[i-1]?c[i-1]-mid:c[i-1]+mid;
            }
        } 
        if(cnt1<=k||cnt2<=k)
        {
            r=mid;
            ans=std::min(ans,mid);
        }
        else l=mid+1;
    }    
    std::cout<<ans;
    return 0;
}