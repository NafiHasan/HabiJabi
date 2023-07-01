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
		string s, t;
		cin >> s >> t;
		if (s[0] != t[0] || s[n - 1] != t[n - 1]) {
			cout << "-1\n";
			continue;
		}
		vector<pair<int, int>> sp, tp;
		int pre = -1;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1' && pre == -1) {
				pre = i;
			} else if (s[i] == '0' && pre != -1) {
				sp.push_back({pre, i - 1});
				pre = -1;
			}
		}
		if (pre != -1) {
			sp.push_back({pre, n - 1});
		}
		pre = -1;
		for (int i = 0; i < n; i++) {
			if (t[i] == '1' && pre == -1) {
				pre = i;
			} else if (t[i] == '0' && pre != -1) {
				tp.push_back({pre, i - 1});
				pre = -1;
			}
		}
		if (pre != -1) {
			tp.push_back({pre, n - 1});
		}
		if (sp.size() != tp.size()) {
			cout << "-1\n";
			continue;
		}
		long long ans = 0;
		for (int i = 0; i < sp.size(); i++) {
			ans += abs(sp[i].first - tp[i].first);
			ans += abs(tp[i].second - sp[i].second);
		}
		cout << ans << '\n';
	}
	return 0;
}