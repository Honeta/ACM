#include<iostream>
#include<vector>
int main()
{
    int n,sum=0;
    std::vector<int> a;
    std::cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++)
    {
        std::cin>>a[i];
        sum^=a[i];
    }
    for(int i=0;i<n;i++)
        std::cout<<(a[i]^sum)<<' ';    
    return 0;
}