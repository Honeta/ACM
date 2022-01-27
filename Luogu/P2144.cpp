#include<iostream>
void debug(double mat[101][101],int n)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            std::cout<<mat[i][j]<<' ';
        std::cout<<std::endl;
    }
}
int det(double mat[101][101],int n)
{
    for(int k=0;k<=n;k++)
    {
        if(mat[k][k]==0)
            for(int i=k+1;i<=n;i++)
                if(mat[i][k])
                {
                    for(int j=k;j<=n;j++)
                        mat[k][j]+=mat[i][j];
                    break;
                }
        for(int i=0;i<=n;i++)
        {
            if(i==k||mat[i][k]==0)continue;
            double temp=mat[i][k]/mat[k][k];
            for(int j=k;j<=n;j++)
                mat[i][j]-=mat[k][j]*temp;
        }
    }
    double ans=1;
    for(int i=0;i<n;i++)
        ans*=mat[i][i];
    return ans;
}
int main()
{
    int n;
    double deg[101][101],adj[101][101],lap[101][101];
    std::cin>>n;
    deg[0][0]=n;
    for(int i=1;i<=n;i++)
    {
        deg[i][i]=3;
        adj[i][0]=adj[0][i]=1;
        if(i<n)adj[i][i+1]=adj[i+1][i]=1;
        else adj[n][1]=adj[1][n]=1;
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            lap[i][j]=deg[i][j]-adj[i][j];
    std::cout<<det(lap,n);
    return 0;
}