#include<iostream>
#include<algorithm>
#include<iomanip>
int main()
{
    int n;
    long long d,maxdelta1=-1e11,mindelta1=1e11,maxdelta2=-1e11,mindelta2=1e11;
    std::cin>>n>>d;
    for(int i=0;i<n;i++)
    {
        long long x,delta1,delta2;
        std::cin>>x;
        delta1=x-i*d;
        delta2=x-i*(-d);
        mindelta1=std::min(mindelta1,delta1);
        maxdelta1=std::max(maxdelta1,delta1);
        mindelta2=std::min(mindelta2,delta2);
        maxdelta2=std::max(maxdelta2,delta2);
    }
    long long ans=std::min(maxdelta1-mindelta1,maxdelta2-mindelta2);
    std::cout<<std::fixed<<std::setprecision(1)<<ans/2<<(ans&1?".5":".0");
    return 0;
}