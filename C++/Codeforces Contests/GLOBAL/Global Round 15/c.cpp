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
		vector<pair<int, int>>v;
		map<int, int>done;
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			// if (n == 10)cout << a << " " << b << "\n";
			done[a]++;
			done[b]++;
			v.push_back({min(a, b), max(a, b)});
		}
		// sort(v.begin(),v.end());
		vector<int>d;
		for (int i = 0; i < 2 * n; i++) {
			if (done[i] < 1)d.push_back(i + 1);
		}
		sort(d.begin(), d.end());
		int cur = d[n - k];
		for (int i = 1; i <= 2 * n; i++) {
			if (done[i] == 0) {
				done[i]++;
				while (done[cur] > 0) {
					cur++;
				}
				if (cur > 2 * n)break;
				done[cur]++;
				v.push_back({i, cur});
			}
		}
		sort(v.begin(), v.end());
		// for (int i = 0; i < v.size(); i++)cout << v[i].first << " " << v[i].second << "\n";
		int ans = 0;
		for (int i = 0; i < v.size() - 1; i++) {
			for (int j = i + 1; j < v.size(); j++) {
				if (v[j].first < v[i].second && v[j].second > v[i].second && v[i].first < v[j].first) {
					ans++;
					// cout << v[i].first << " " << v[i].second << " " << v[j].first << " " << v[j].second << "\n";
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}