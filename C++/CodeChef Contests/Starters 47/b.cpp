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
		vector<int> a(n);
		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
		}
		sort(a.begin(), a.end());
		int mx = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (mp[a[i]] == 1) {
				cnt++;
			}
			if (i < n - 1) {
				mx = max(mx, mp[a[i]]);
			}
		}
		if (a[n - 1] != a[n - 2] && cnt == 1) {
			if (mx <= 2)cout << mx << '\n';
			else cout << 1 << '\n';
		} else {
			cout << (cnt + 1) / 2 << '\n';
		}
	}
	return 0;
}