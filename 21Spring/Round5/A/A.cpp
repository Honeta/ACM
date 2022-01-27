#include<iostream>
#include<algorithm>
int main()
{
    int t;
    std::cin>>t;
    while(t--)
    {
        int num[27],ans=0,max=0;
        for(int i=1;i<=26;i++)
        {
            std::cin>>num[i];
            max=std::max(max,num[i]);
        }
        for(int k=2;k<=max;k++)
        {
            int temp=0;
            for(int i=1;i<=26;i++)
                temp+=num[i]-num[i]%k;
            ans=std::max(ans,temp);
        }
        std::cout<<ans<<std::endl;
    }
    return 0;
}