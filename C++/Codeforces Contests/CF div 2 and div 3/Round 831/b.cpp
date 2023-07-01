#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

signed main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> v(n);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			if (a > b)swap(a, b);
			v[i] = b;
			ans += 2LL * a;
		}
		sort(v.begin(), v.end());
		for (int i = 1; i < n; i++) {
			ans += v[i] - v[i - 1];
		}
		ans += v[0] + v[n - 1];
		cout << ans << '\n';
	}
	return 0;
}