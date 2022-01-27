#include<cstdio>
int main()
{
    int n;
    bool flag=0;
    double mat[51][52];
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n+1;j++)
            scanf("%lf",&mat[i][j]);
    for(int k=1;k<=n;k++)
    {
        if(mat[k][k])continue;
        for(int i=1;i<=n;i++)
            if(mat[i][k])
            {
                for(int j=1;j<=n+1;j++)
                    mat[k][j]+=mat[i][j];
                break;
            }
    }
    for(int k=1;k<=n;k++)
    {
        if(!mat[k][k])
            for(int i=k+1;i<=n;i++)
                if(mat[i][k])
                {
                    for(int j=1;j<=n+1;j++)
                        mat[k][j]+=mat[i][j];
                    break;
                }
        if(!mat[k][k])
        {
            ++flag;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(i==k||mat[i][k]==0)continue;
            double temp=mat[i][k]/mat[k][k];
            for(int j=k;j<=n+1;j++)
                mat[i][j]-=mat[k][j]*temp;
        }
    }
    if(flag)
    {
        for(int i=n;i>n-flag;i--)
            if(mat[i][n+1])
            {
                printf("-1");
                return 0;
            }
        printf("0");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        double temp=mat[i][i];
        for(int j=1;j<=n+1;j++)
            mat[i][j]/=temp;
    }
    for(int i=1;i<=n;i++)
        printf("x%d=%.2lf\n",i,mat[i][n+1]);
    return 0;    
}