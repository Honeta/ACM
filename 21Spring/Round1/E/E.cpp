#include<iostream>
int Det(double mat[51][51],int n)
{
    const double MOD=1e9+7;
    for(int k=1;k<=n;k++)
    {
        if(mat[k][k]==0)
            for(int i=k+1;i<=n;i++)
                if(mat[i][k])
                {
                    for(int j=k;j<=n;j++)
                        mat[k][j]+=mat[i][j];
                    break;
                }
        for(int i=1;i<=n;i++)
        {
            if(i==k||mat[i][k]==0)continue;
            double temp=mat[i][k]/mat[k][k];
            for(int j=k;j<=n;j++)
                mat[i][j]-=mat[k][j]*temp;
        }
    }
    double ans=1;
    for(int i=1;i<=n;i++)
    {
        while(mat[i][i]>MOD)
            mat[i][i]-=MOD;
        ans*=mat[i][i];
        while(ans>MOD)
            ans-=MOD;    
    }
    return ans;
}
int main()
{
    int n,m,k;
    double adj[51][51],deg[51][51],lap[51][51];
    int x[51];
    std::cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        if(w)++k;
        std::cin>>u>>v>>w;
        ++deg[u][u];
        ++deg[v][v];
        adj[u][v]=adj[v][u]=(w?-1:1);
    }
    for(int X=1;X<=50;X++)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                lap[i][j]=deg[i][j]-(adj[i][j]==-1?X:adj[i][j]);
        x[X]=Det(lap,n);        
    }
    return 0;
}