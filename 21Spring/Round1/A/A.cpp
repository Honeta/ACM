#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<=3)cout<<"No";
    else
    {
        cout<<"Yes"<<endl;
        if(!(n&1))
        {
            cout<<"1*2*3*4";
            for(int i=5;i<=n;i+=2)
                cout<<"*("<<i+1<<"-"<<i<<")";
        }
        else
        {
            cout<<"3*(1-2+4+5)";
            for(int i=6;i<=n;i+=2)
                cout<<"*("<<i+1<<"-"<<i<<")";
        }
    }
    return 0;
}