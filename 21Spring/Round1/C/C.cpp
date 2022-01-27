#include<iostream>
using namespace std;
int n,e[100001],ans;
const int mod=1e9+7;
void eular()
{
    e[1]=1;
    for(int i=2;i<=n;i++) 
        if(!e[i])  
            for(int j=i;j<=n;j+=i)
            {  
                if(!e[j])e[j]=j;  
                e[j]=e[j]/i*(i-1);  
            }  
}
int main()
{
    cin>>n;
    eular();
    for(int i=1;i<=n;i++)
        for(int j=1;i*(j+1)<=n;j++)
            if(i==(i*j^i*(j+1)))
                (ans+=(e[i]<<1))%=mod;
    cout<<ans;
    return 0;
}