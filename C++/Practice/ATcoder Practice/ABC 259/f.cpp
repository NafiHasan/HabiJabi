#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int n;
	cin >> n;
	vector<int> mx(n + 5);
	for (int i = 1; i <= n; i++)cin >> mx[i];
	vector<pair<int, pair<int, int>>> vp(n - 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		vp[i] = {w, {u, v}};
	}
	sort(vp.rbegin(), vp.rend());
	long long ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if (vp[i].first > 0 && mx[vp[i].second.first] > 0 && mx[vp[i].second.second] > 0) {
			ans += (long long)vp[i].first;
			mx[vp[i].second.first]--;
			mx[vp[i].second.second]--;
		}
	}
	cout << ans << '\n';
	return 0;
}