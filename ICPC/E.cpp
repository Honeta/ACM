#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    cin>>s;
    int pos=0,ans=0;
    while(pos!=-1)
    {
        pos=s.find("edgnb",pos);
        if(pos==-1) break;
        pos+=5;
        ans++;
    }
    cout<<ans<<endl;
}