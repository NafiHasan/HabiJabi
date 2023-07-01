#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n ;
		cin >> n;
		vector<pair<int, int>>v(n);
		// priority_queue<pair<int,int>>pq;
		for (int i = 0; i < n; i++) {
			cin >> v[i].first;
			v[i].second = i;
			// pq.push({v[i].first, i});
		}
		sort (v.begin(), v.end());
		int i = 0;
		vector<pair<int, int>>ans;
		for (i = 0; i < n - 1 ; i++) {
			if (v[i].first == 0) {
				continue;
			}
			// while (v[i].first == 0 && i < n) {
			// 	i++;
			// 	// ind++;
			// 	// continue;
			// }
			// if (i >= n)break;
			int last = n - 1;
			int mn = v[i].first, mx = v[n - 1].first;
			int lo = i + 1, hi = n - 1, mid;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (v[mid].first == mx) {
					last = mid;
					hi = mid - 1;
				} else lo = mid + 1;
			}
			ans.push_back({v[i].second + 1, v[last].second + 1});
			v[i].first--;
			v[last].first--;
			if (v[i].first > 0)i--;
		}
		cout << ans.size() << '\n';
		for (int j = 0; j < ans.size(); j++)cout << ans[j].first << ' ' << ans[j].second << '\n';
	}
	return 0;
}