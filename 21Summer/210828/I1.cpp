#include<bits/stdc++.h>
#define go(i, n) for(int i = 1; i <= n; i++)
#define dec(i, n) for(int i = n; i >= 1; i--)
using namespace std;
typedef long long ll;
typedef unsigned int uint;
const int MAXN = 1e5+1;
//const int MOD = ;

int L[MAXN],R[MAXN],U[MAXN],D[MAXN];
ll sum[MAXN];
ll f[MAXN];
int cntl,cntr,cntu,cntd;
int n;
char s[MAXN];
int tot = 0;
void work(){
	tot ++;
	ll ans = 0;
	cntl = 0;
	cntr = 0;
	cntu = 0;
	cntd = 0;
	memset(f,0,sizeof(f));
	scanf("%d%s",&n,s+1);
	int v;
	for(int i = 1; i <= n ; i++){
		if(s[i] == 'L') v = 1;
		if(s[i] == 'R') v = -1;
		if(s[i] == 'U') v = MAXN;
		if(s[i] == 'D') v = -MAXN;
		sum[i] = sum[i-1] + v;
	}
	int cl = 0, cr = 0, cu = 0, cd = 0;
	int coupl = -1, coupr = -1, coupu = -1, coupd = -1;
	int prev, prex;
	for(int i = 1; i <= n; i++){
		if(s[i] == 'L'){
			if(cntr)prev = R[cntr--];
			else prev = -1;
			coupl = prev;
			L[++cntl] = i;
			cr = 0;
			cl = i;
			if(cu>prev) prex = coupu;
			else if(cd>prev) prex = coupd;
			else prex = -1;
		}
		
		if(s[i] == 'R'){
			if(cntl)prev = L[cntl--];
			else prev = -1;
			coupr = prev;
			R[++cntr] = i;
			cl = 0;
			cr = i;
			if(cu>prev) prex = coupu;
			else if(cd>prev) prex = coupd;
			else prex = -1;
		}
		
		if(s[i] == 'U'){
			if(cntd)prev = D[cntd--];
			else prev = -1;
			coupu = prev;
			U[++cntu] = i;
			cd = 0;
			cu = i;
			if(cl>prev) prex = coupl;
			else if(cr>prev) prex = coupr;
			else prex = -1;
		}
		
		if(s[i] == 'D'){
			if(cntu)prev = U[cntu--];
			else prev = -1;
			coupd = prev;
			D[++cntd] = i;
			cu = 0;
			cd = i;
			if(cl>prev) prex = coupl;
			else if(cr>prev) prex = coupr;
			else prex = -1;
		}
		if(prev != -1 && sum[i] - sum[prev-1] == 0){
			f[i] += f[prev-1]+1;
		}
		if(prex != -1 && sum[i] - sum[prex-1] == 0){
			f[i] += f[prex-1]+1;
		}
		ans += f[i];
	}
	printf("%lld\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
