#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		vector<int>v(n);
		map<int, int>m, col;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			m[v[i]]++;
		}
		vector<int> ans(n, 0);
		deque<pair<int, int>>nc;
		for (int i = 0; i < n; i++) {
			if (m[v[i]] >= k && col[v[i]] < k) {
				ans[i] = col[v[i]] + 1;
				col[v[i]]++;
			} else if (m[v[i]] < k) {
				nc.push_back({v[i], i});
			}
		}
		sort(nc.begin(), nc.end());
		while ((int)nc.size() >= k) {
			int cur = 1;
			while (cur <= k) {
				ans[nc[0].second] = cur++;
				nc.pop_front();
			}
		}
		for (int i = 0; i < n ; i++)cout << ans[i] << " ";
		cout << "\n";
	}
	return 0;
}