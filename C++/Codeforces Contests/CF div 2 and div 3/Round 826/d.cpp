#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


bool ans = 1;
int cnt = 0;
vector<int> a(262145);


int rec(int l, int r) {
	// cout << l << ' ' << r << '\n';
	if (l == r - 1) {
		if (a[l] > a[r])cnt++;
		if (abs(a[l] - a[r]) > 1)ans = 0;
		return min(a[l], a[r]);
	}
	int lo = l, hi = r, mid = (l + r) / 2;
	int mn1 = rec(lo, mid), mn2 = rec(mid + 1, hi);
	if (abs(mn1 - mn2) > (r - l))ans = 0;
	if (mn1 > mn2)cnt++;
	return min(mn1, mn2);
}


int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)cin >> a[i];
		if (n == 1) {
			cout << "0\n";
			continue;
		}
		ans = 1;
		cnt = 0;
		rec(0, n - 1);
		if (ans) {
			cout << cnt << '\n';
		} else cout << "-1\n";
	}
	return 0;
}