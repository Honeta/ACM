#include <iostream>
#include <algorithm>
struct tree{
	int l, r;
	long long pre,add;
}t[800001];
int n,m,t1,t2,t3,t4,v[200001];
inline void up(int i)
{
	t[i].pre=t[i<<1].pre+t[i<<1|1].pre;
}
inline void down(int i)
{
	t[i<<1].add+=t[i].add;
	t[i<<1].pre+=t[i].add*(t[i<<1].r-t[i<<1].l+1);
	t[i<<1|1].add+=t[i].add;
	t[i<<1|1].pre+=t[i].add*(t[i<<1|1].r-t[i<<1|1].l+1);
	t[i].add=0;
}
void build(int i,int l,int r)
{
	t[i].add=0;
	t[i].l=l;
	t[i].r=r;
	if(l==r)
	{
		t[i].pre=v[l];
		return;
	}
	int mid=t[i].l+t[i].r>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	up(i);
}
long long ask(int i,int l,int r)
{
	long long ans=0;
	if(l<=t[i].l&&t[i].r<=r)return t[i].pre;
	down(i);
	int mid=t[i].l+t[i].r>>1;
	if(l<=mid)ans+=ask(i<<1,l,r);
	if(mid+1<=r)ans+=ask(i<<1|1,l,r);
	return ans;
}
void edit(int i,int l,int r,int d)
{
	if(l<=t[i].l&&t[i].r<=r)
	{
		t[i].pre+=d*(t[i].r-t[i].l+1);
		t[i].add+=d;
		return;
	}
	down(i);
	int mid=t[i].l+t[i].r>>1;
	if(l<=mid)edit(i<<1,l,r,d);
	if(mid+1<=r)edit(i<<1|1,l,r,d);
	up(i);
}
int main() {
    int n, q, a[200001];
    std::cin >> n >> q;
    int st = 1;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];		
        if (i > 1 && a[i] < a[i - 1])
            st = i;
		if (i != st)
            v[i] = i - st;
		++v[i];
		//std::cout << v[i] << ' ';
    }
	//std::cout << std::endl;
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int opt, t1, t2;
        std::cin >> opt >> t1 >> t2;
        if (opt == 1) {	
			int temp1 = ask(1, t1, t1);
			if (t1 > 1) {
				if (a[t1] >= a[t1 - 1] && t2 < a[t1 - 1])
					edit(1, t1, t1, 1 - temp1);
				if (a[t1] < a[t1 - 1] && t2 >= a[t1 - 1])
					edit(1, t1, t1, ask(1, t1 - 1, t1 - 1));
			}			
			if (t1 < n) {
				int pos = 0, temp = ask(1, t1 + 1, t1 + 1);			
				int l = t1 + 1, r = n + 1;
				while (l < r) {
					int mid = l + r >> 1;
					if (ask(1, mid, mid) == temp + (mid - t1 - 1)) {
						pos = std::max(pos, mid);
						l = mid + 1;
					} else {
						r = mid;
					}
				}
				int temp2 = ask(1, t1, t1);
				if (a[t1] > a[t1 + 1] && t2 <= a[t1 + 1])
					edit(1, t1 + 1, pos, temp2);	
				if (a[t1] <= a[t1 + 1] && t2 > a[t1 + 1])
					edit(1, t1 + 1, pos, -temp1);
				if (a[t1] <= a[t1 + 1] && t2 <= a[t1 + 1])
					edit(1, t1 + 1, pos, temp2 - temp1);
			}
			a[t1] = t2;/*
			for (int i = 1; i <= n; i++)
				std::cout << ask(1, i, i) << ' ';
			std::cout << std::endl;*/
        } else {
			if (t1 == 1 || a[t1] < a[t1 - 1]) {
				std::cout << ask(1, t1, t2) << std::endl;
			} else {
				int pos = 0, temp = ask(1, t1 - 1, t1 - 1);
				int l = t1, r = t2 + 1;
				while (l < r) {
					int mid = l + r >> 1;
					if (ask(1, mid, mid) == temp + (mid - t1 + 1)) {
						pos = std::max(pos, mid);
						l = mid + 1;
					} else {
						r = mid;
					}
				}
				std::cout << ask(1, t1, t2) - (pos - t1 + 1) * temp << std::endl;
			}				
        }
    }
    return 0;
}