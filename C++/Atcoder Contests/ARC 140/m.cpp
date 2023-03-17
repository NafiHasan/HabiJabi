#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		long long n, m;
		cin >> n >> m;
		vector<long long> a;
		map<long long, long long> mp;
		for (int i = 0; i < n; i++) {
			long long x;
			cin >> x;
			mp[x]++;
			if (mp[x] == 1)a.push_back(x);
		}
		sort(a.begin(), a.end());
		n = a.size();
		long long ans = 0;
		ans = max(ans, a[n - 1] * 2LL);
		if (n > 1) {
			long long md = (((a[n - 1] - a[n - 2]) % m) + m) % m;
			md = max(md, (((a[n - 2] - a[n - 1]) % m) + m) % m);
			ans = max(ans, a[n - 1] + a[n - 2] + md);
		}
		cout << ans << '\n';
	}
	return 0;
}