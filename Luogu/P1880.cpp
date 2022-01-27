#include<cstdio>
#include<algorithm>
#include<cstring>
int main()
{
    int n,a[101],dp_min[101][101],dp_max[101][101];
    memset(dp_min,0x3f,sizeof(dp_min));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&dp_min[i][i]);
        
        dp_max[i][i]=dp_min[i][i];
    }
    for(int len=2;len<=n;len++)
        for(int i=1;i<=n-len+1;i++)
            for(int k=1;k<i+len-1;k++)
            {
                dp_max[i][i+len-1]=std::max(dp_max[i][k]+dp_max[k+1][i+len-1],dp_max[i][i+len-1]);
                dp_min[i][i+len-1]=std::min(dp_min[i][k]+dp_min[k+1][i+len-1],dp_min[i][i+len-1]);
            }    
    printf("%d\n%d",dp_max[1][n],dp_min[1][n]);
    return 0;
}