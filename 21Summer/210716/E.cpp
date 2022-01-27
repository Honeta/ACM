#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int a[210000];
long long m, n;
int ans = -1, ans1 = -1;

int find(int t) {
	int l = 0, r = n - 1, ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (a[mid] >= t) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return ans;
}

int find1(int t) {
	int l = 0, r = n - 1, ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (a[mid] <= t) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return ans;
}

bool check(int val) {
	long long count = 0;
	for (int i = 0; i < n - 1; i++) {
		int t = find(a[i] + val);
		if (t != -1)
			count += n - t;
	}
	return count > m;
}

bool check1(int val) {
	long long count = 0;
	for (int i = 0; i < n - 1; i++) {
		int t = find1(a[i] + val);
		if (t != -1)
			count += n - t;
	}
	return count > m;
}

int main() {
    cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	m = n * (n - 1) / 4;
	int l = 0, r = a[n - 1] - a[0];
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		}
		else {
			r = mid - 1;
		}
	}
     l = 0; r = a[n - 1] - a[0];
    while (l <= r) {
		int mid = (l + r) / 2;
		if (check1(mid)) {
			l = mid + 1;
			ans1 = mid;
		}
		else {
			r = mid - 1;
		}
	}
	cout << (ans + ans1) / 2.0;
}
