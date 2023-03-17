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
		vector<int> a(n);
		vector<pair<int, int>> vp;
		map<int, int> has;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			// cin >> vp[i].first >> vp[i].second;
			vp.push_back({x, y});
			has[x]++;
		}
		for (int i = 1; i <= n; i++) {
			if (has[i] > 0)continue;
			vp.push_back({i, n});
		}
		sort(vp.rbegin(), vp.rend());
		// for (int i = 0; i < vp.size(); i++) {
		// 	cout << vp[i].first << ' ' << vp[i].second << '\n';
		// }
		bool ans = 1;
		set<int, greater<int>> ind;
		for (int i = 1; i <= n; i++)ind.insert(i);
		for (int i = 0; i < vp.size(); i++) {
			int need = vp[i].second;
			if (ind.find(need) != ind.end()) {
				ind.erase(need);
				// cout << need << '\n';
				a[need - 1] = vp[i].first;
			} else if (ind.lower_bound(need) == ind.end()) {
				ans = 0;
				// cout << need << '\n';
				break;
			} else {
				need = *ind.lower_bound(need);
				ind.erase(need);
				a[need - 1] = vp[i].first;
			}
		}
		if (ans) {
			for (int i = 0; i < n; i++)cout << a[i] << ' ';
			cout << "\n";
		} else cout << "-1\n";
	}
	return 0;
}