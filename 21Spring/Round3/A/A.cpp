#include<iostream>
int main()
{
    int t;
    std::cin>>t;
    while(t--)
    {
        int n,k;
        std::cin>>n>>k;
      	if(k==0)
        {
            std::cout<<"Yes"<<std::endl;
            continue;
        }
        if(k==1)
        {
            std::cout<<"No"<<std::endl;
            continue;
        }
        std::cout<<((n-1)%k==0?"Yes":"No")<<std::endl;       
    }
    return 0;
}