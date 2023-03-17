#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n + 1, 0);
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			a[x]++;
		}
		int ans = INT_MAX;
		int lo = 1, hi = INT_MAX - 1, mid;
		map<int, int> mp;
		while (lo <= hi) {
			mid = (lo  + hi) / 2;
			bool don = 1;
			mp.clear();
			vector<int> av(n + 1);
			av = a;
			for (int i = 1; i <= n; i++) {
				mp[i] += min(av[i], mid);
				av[i] -= mid;
				av[i] = max(av[i], 0);
			}
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
			for (int i = 1; i <= n; i++) {
				pq.push({mp[i], i});
			}
			vector<int> tmp;
			for (int i = 1; i <= n; i++) {
				while (av[i] > 0) {
					tmp.push_back(i);
					av[i]--;
				}
			}
			for (int i = 0; i < tmp.size(); i++) {
				if (pq.size() == 0) {
					don = 0;
					break;
				}
				pair<int, int> tp = pq.top();
				pq.pop();
				if (tp.second == tmp[i]) {
					if (tp.first >= mid) {
						don = 0;
						break;
					} else {
						tp.first++;
						pq.push(tp);
					}
				} else {
					if (tp.first + 1 >= mid) {
						don = 0;
						break;
					} else {
						tp.first += 2;
						pq.push(tp);
					}
				}
			}
			if (don == 1) {
				ans = min(ans, mid);
				hi = mid - 1;
			} else lo = mid + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}