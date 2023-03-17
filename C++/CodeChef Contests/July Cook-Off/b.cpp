#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> a(n);
		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
		}
		int cnt = 0, mex = 0;
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++) {
			if (a[i] == k)break;
			cnt++;
		}
		for (int i = 0; i < n; i++) {
			// if (cnt >= m)break;
			if (a[i] <= k)continue;
			cnt++;
		}
		bool ans = 1;
		for (int i = 0; i < k; i++) {
			if (mp[i] == 0)ans = 0;
		}
		if (cnt >= m && ans && m >= k)cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}