#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
struct pos{long long x,y;};
long long r;
bool cmp(pos x,pos y)
{
    int last1=x.x+sqrt(r*r-x.y*x.y);
    int last2=y.x+sqrt(r*r-y.y*y.y);
    return last1<=last2;
}
int main()
{
    int n,ans=0,last;
    std::cin>>n>>r;
    std::vector<pos> a;
    a.resize(n);
    for(int i=0;i<n;i++)
        std::cin>>a[i].x>>a[i].y;
    std::sort(a.begin(),a.end(),cmp);
    for(int i=0;i<n;i++)
        if(i==0||a[i].y*a[i].y+(a[i].x-last)*(a[i].x-last)>r*r)
        {
            ++ans;
            last=a[i].x+sqrt(r*r-a[i].y*a[i].y);
        }
    std::cout<<ans;
    return 0;
}