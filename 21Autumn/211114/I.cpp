#include<bits/stdc++.h>
using namespace std;
long long H,M,A;
long long gcd(long long a,long long b)
{
    return (b==0)?a:gcd(b,a%b);
}
int main()
{
    cin>>H>>M>>A;
    long long g=gcd(H-1,H*M);
    cout<<min(H*M,g*(2*A/g+1))<<endl;
}