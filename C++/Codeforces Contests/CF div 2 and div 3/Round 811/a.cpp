#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, H, M;
		cin >> n >> H >> M;
		vector<pair<int, int>> vp(n);
		for (int i = 0; i < n; i++) {
			cin >> vp[i].first >> vp[i].second;
			if (vp[i].second < M) {
				vp[i].second += 60;
				vp[i].first--;
			}
			if (vp[i].first < H)vp[i].first += 24;
		}
		sort(vp.begin(), vp.end());
		// vector<pair<int, int>> ans;
		// for (int i = 0; i < n; i++) {
		// 	pair<int, int> p;
		// 	p.second = abs(vp[i].second - M);
		// 	p.first = abs(vp[i].first - H);
		// 	if (vp[i].second < M)p.first--;
		// 	ans.push_back(p);
		// }
		// sort(ans.begin(), ans.end());
		cout << vp[0].first - H << ' ' << vp[0].second - M << '\n';
	}
	return 0;
}