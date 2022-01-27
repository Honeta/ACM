#include<iostream>
#include<algorithm>
bool NoPrime[10000001],NoPrimeL[1000001];
int main()
{
    long long l,r,ans=0;
    std::cin>>l>>r;
    for(long long i=2;i*i<=r;i++)
        if(!NoPrime[i])
        {
            for(long long j=2;i*j*i*j<=r;j++)
                NoPrime[i*j]=1;
            for(long long j=std::max(2ll,(l+i-1)/i);j*i<=r;j++)
                NoPrimeL[i*j-l]=1;
        }
    for(long long i=0;i<=r-l;i++)
        if(i+l>1&&!NoPrimeL[i])
            ans^=i+l;
    std::cout<<ans;      
    return 0;
}