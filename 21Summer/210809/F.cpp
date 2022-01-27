#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int f=1,sum=0;char c=getchar();
    while(c<'0' || c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0' && c<='9'){sum=sum*10+c-'0';c=getchar();}
    return sum*f;
}
int n,m;
char s[505][505];
int fa1[505][505],fa2[505][505];
bool col1[505][505],col2[505][505];
struct node{
	int x,y;
};
queue<node> q;
void bfs1(int x,int y,int col)
{
	cout<<x<<' '<<y<<' '<<col<<endl;
	q.push((node){x,y});
	col1[x][y]=col;
	while(!q.empty())
	{
		node now=q.front();
		q.pop();
		col1[now.x][now.y]=col;
		if(now.y+1<=m && !col1[now.x][now.y+1] && s[now.x][now.y+1]=='0'){col1[now.x][now.y+1]=1;q.push((node){now.x,now.y+1});}
		if(now.x+1<=n && !col1[now.x+1][now.y] && s[now.x+1][now.y]=='0'){col1[now.x+1][now.y]=1;q.push((node){now.x+1,now.y});}
	}
}
void bfs2(int x,int y,int col)
{
	q.push((node){x,y});
	while(!q.empty())
	{
		node now=q.front();
		q.pop();
		col2[now.x][now.y]=col;
		if(now.y-1>=1 && !col2[now.x][now.y-1] && s[now.x][now.y-1]=='0'){col2[now.x][now.y-1]=1;q.push((node){now.x,now.y-1});}
		if(now.x-1>=1 && !col2[now.x-1][now.y] && s[now.x-1][now.y]=='0'){col2[now.x-1][now.y]=1;q.push((node){now.x-1,now.y});}
	}
}
queue<int> q1;
void bfs3(int x,int y,int col)
{
	q1.push(y);
	while(!q1.empty())
	{
		int now=q1.front();
		q1.pop();
		fa1[x][now]=col;
		if(now+1<=m && !col1[x][now+1] && s[x][now+1]=='0') {col1[x][now+1]=1;q1.push(now+1);}
	}
}
void bfs4(int x,int y,int col)
{
	queue<int> q1;
	q1.push(x);
	while(!q1.empty())
	{
		int now=q1.front();
		q1.pop();
		fa2[now][y]=col;
		if(y+1<=m && !col2[now+1][y] && s[now+1][y]=='0') {col2[now+1][y]=1;q1.push(now+1);}
	}
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	int col=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(s[i][j]=='0')
	{
		if(!col1[i][j])
		{
			bfs1(i,j,col);
			col++;
		}
	}
	cout<<col1[4][4]<<endl;
	col=1;
	for(int i=n;i>=1;i--)
	for(int j=m;j>=1;j--)
	if(s[i][j]=='0')
	{
		if(!col2[i][j])
		{
			bfs2(i,j,col);
			col++;
		}
	}
	memset(col1,0,sizeof(col1));
	memset(col2,0,sizeof(col2));
	col=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(s[i][j]=='0')
	{
		if(!fa1[i][j])
		{
			bfs3(i,j,col);
			col++;
		}
	}
	col=1;
	for(int j=1;j<=m;j++)
	for(int i=1;i<=n;i++)
	if(s[i][j]=='0')
	{
		if(!fa2[i][j])
		{
			bfs4(i,j,col);
			col++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		cout<<col1[i][j];
		cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		cout<<col2[i][j];
		cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		cout<<fa1[i][j];
		cout<<endl;
	}
	cout<<endl;
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		cout<<fa2[j][i];
		cout<<endl;
	}
}