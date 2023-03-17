#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<pair<int, int>> a(n), sorted(n);
		vector<int> ans(n);
		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i].first;
			a[i].second = i;
		}
		sorted = a;
		int mod = 1e9 + 7;
		sort(sorted.begin(), sorted.end());
		for (int i = 0; i < n; i++) {
			int minus = mod;
			minus -= a[i].first;
			int lo = 0, hi = n - 1, mid, ind = 0;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (sorted[mid].first < minus) {
					ind = mid;
					lo = mid + 1;
				} else hi = mid - 1;
			}
			int tmp = n - 1;
			if (sorted[ind].second == i) {
				if (ind > 0)ind--;
				else ind++;
			}
			if (sorted[n - 1].second == i)tmp--;
			ans[i] = max((a[i].first + sorted[tmp].first) % mod , (a[i].first + sorted[ind].first ) % mod);
		}
		for (int i = 0; i < n; i++)cout << ans[i] << ' ' ;
		cout << "\n";
	}
	return 0;
}