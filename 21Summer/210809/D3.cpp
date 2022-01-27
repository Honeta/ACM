#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int b[201010],c[200101],d[201010],vis[200101][40],p[201000][40],ans[201001][40];
int main()
{
	int n;
	cin>>n;
	for(int i=2;i<=n;i++)
	scanf("%d",&b[i]);
	for(int i=2;i<=n;i++)
	scanf("%d",&c[i]),d[i]=c[i]-b[i];
	for(int i=2;i<=n;i++)
	{
		int k=d[i],c=-1;
		if(k<0) {printf("0");return 0;}
		while(k)
		{
			vis[i][++c]=k%2;
			k/=2;
		}
	}
	for(int i=2;i<=n;i++)
	{
		int t=b[i]-d[i];
		for(int j=0;j<=30;j++)
		if(t&(1<<j))
		p[i][j]=1;
	}
	for(int i=2;i<=n;i++)
	for(int j=0;j<=30;j++)
	{
		if(vis[i][j])
		ans[i-1][j]=1,ans[i][j]=1;
	}
	int rans=1;
	for(int j=0;j<=30;j++)
	{
		int cnt=0;
		for(int pe=0;pe<=1;pe++)
		{
			int pre=pe;int f=1;
			for(int i=2;i<=n;i++)
			{
				if(p[i][j])
				{
					if(pre==0)
					pre=1;
					else
					{
						if(ans[i][j])
						{f=0;break;}
						pre=0;
					}
				}
				else 
				{
					if(!vis[i][j])
					{
						if(pre==0)
						pre=0;
						else
						{f=0;break;}
					}
					else
					{
						if(pre==1)
						pre=1;
						else
						{f=0;break;}
					}
				}
			}
			if(f) cnt++;
		}
		rans=rans*cnt;
	}
	cout<<rans;
}