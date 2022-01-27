#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>


void ins_sort(int b[], int n, int k) {
    int i = 1;
    while (i <= n && i <= k) {
        int j = i;
        while (j > 1 && b[j - 1] > b[j]) {
            std::swap(b[j], b[j - 1]);
            --j;
        }
        ++i;       
    }
}

bool isvalid(int a[], int n, int k) {
    int b[n + 1];
    for(int i=1;i<=n;i++) b[i]=a[i];
    ins_sort(b, n, k);
    std::vector<int> temp(n+1,1);
        int maxNum=1;
        for(int i=2;i<=n;i++)//以v[i]为结尾元素时
        {
            for(int j=1;j<i;j++)
            {
                if(b[j]<b[i])
                    temp[i]=std::max(temp[i],temp[j]+1);
            }
            maxNum=std::max(temp[i],maxNum);//判断哪个结尾元素所出现的升序子序列最长
        }
    if(maxNum>=n-1) return true;
    return false;
}

int main() {    
    int a[51];
    int n, k;
    int ans=0;
    //std::cin >> n >> k;
    
    for(n=1;n<=8;n++)
    {
        for(k=1;k<=8;k++)
        {
            ans=0;
            for (int i = 1; i <= n; i++) a[i] = i;
            do {
                if(isvalid(a,n,k)) ans++;
            } while (std::next_permutation(a + 1, a + n + 1));
            std::cout<<ans<<' ';
        }
        std::cout<<std::endl;
    }
    
    
    
}