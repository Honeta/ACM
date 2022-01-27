#include<iostream>
#include<vector>
#include<algorithm>
struct student{
    int l,r;
};
bool cmp(student x,student y)
{
    if(x.r==y.r)return x.l>y.l;
    return x.r<y.r;
}
int main()
{
    int n,now=0;
    long long ans=0;
    std::cin>>n;
    std::vector<student> a;
    a.resize(n);
    for(int i=0;i<n;i++)
        std::cin>>a[i].l>>a[i].r;
    std::sort(a.begin(),a.end(),cmp);
    for(int i=0;i<n;i++)
    {
        now=std::max(now,a[i].l);
        ans+=now;
    }
    std::cout<<ans;
    return 0;
}