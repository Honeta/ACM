#include <iostream>
#include <list>
#include <cmath>
std::list<int> prime;
bool is_prime[2000001];//is_prime[i]为true表示i是素数
int cnt[30];
void sieve(int n)//返回n以内的素数
{
    for(int i=0;i<=n;i++)
        is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
        if(is_prime[i])
        {
            prime.push_back(i);
            for(int j=2*i;j<=n;j+=i)
                is_prime[j]=false;
        }
}
int main() {
    sieve(1500000);
    for (auto it = prime.begin(); it != prime.end(); ++it)
        cnt[(int)log2(*it)]++;
    int t, x;
    std::cin >> t;
    while (t--) {
        int sum = 0;
        std::cin >> x;
        for (int i = 1;i <= (int)log2(x); i++)
            if (x & (1 << i))
                sum += cnt[i];
        std::cout << sum << std::endl;
    }
    return 0;
}