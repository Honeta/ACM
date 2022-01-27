#include<iostream>
int main()
{
    unsigned long long x,y;
    std::cin>>x>>y;
    if((x^y)<x)
        std::cout<<1<<std::endl<<(x^y);
    else std::cout<<2<<std::endl<<y<<' '<<x;
    return 0;
}