#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long


signed main() {
	FastIO;
	int n;
	cin >> n;
	vector<pair<int, int>> vp(n);
	for (int i = 0; i < n; i++)cin >> vp[i].first >> vp[i].second;
	sort(vp.rbegin(), vp.rend());
	int pre = 0, cal = 0, point = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int h = vp[i].second / 2 ;
		if (vp[i].second > pre) {
			int area = vp[i].second - pre;
			area *= vp[i].first;
			ans += area;
		}
		pre = max(pre, vp[i].second);
		// cal = max(cal, )
	}
	cout << ans << '\n';
	return 0;
}