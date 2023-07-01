#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >>  tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<pair<int, int>>a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].first;
			a[i].second = i;
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i].first;
			b[i].second = i;
		}
		sort (a.begin(), a.end());
		sort (b.begin(), b.end());
		vector<int>n1(n), n2(n);
		for (int i = 0; i < n; i++) {
			n1[i] = a[i].second;
			n2[i] = b[i].second;
		}
		vector<int>pre(n, n + 1);
		for (int i = n - 1; i >= 0; i--) {
			if (i == n - 1)pre[i] = n2[i];
			else pre[i] = min(n2[i], pre[i + 1]);
		}
		int ans = n;
		for (int i = 0; i < n; i++) {
			ans = min(ans, n1[i] + pre[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}