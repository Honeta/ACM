#include<iostream>
#include<algorithm>
int main()
{
    int t;
    std::cin>>t;
    while(t--)
    {
        int x,y;
        std::cin>>x>>y;
        if(x>1&&y>1&&std::__gcd(x,y)!=1)
        {
            std::cout<<-1<<std::endl;
            continue;
        }
        int cnt=0;
        while(x!=1&&y!=1)
        {
            if(x>y)x-=y;
            else y-=x;
            ++cnt;
        }
        std::cout<<std::max(x,y)+cnt<<std::endl;
    }
    return 0;
}