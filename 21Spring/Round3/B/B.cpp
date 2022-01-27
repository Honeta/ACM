#include<iostream>
#include<algorithm>
int n,k[122],c[122],sum;
unsigned long long m,f[242001];
int main()
{    
    std::cin>>n>>m;
    for(int i=1;i<=n;i++)
        std::cin>>k[i];  
    for(int i=1;i<=n;i++)
    {
        std::cin>>c[i];
        sum+=c[i]*k[i];
    }
    f[0]=1;
    for(int i=1;i<=n;i++)
        for(int w=sum;w>=c[i];w--)    
            for(int j=1;j<=k[i];j++)
                if(w>=j*c[i])  
                    f[w]=std::max(f[w],f[w-j*c[i]]*j);
    for(int i=1;i<=sum;i++)
        if(f[i]>=m)
        { 
            std::cout<<i;
            return 0;
        }
}