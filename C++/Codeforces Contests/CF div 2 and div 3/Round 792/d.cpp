#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		long long n, k;
		cin >> n >> k;
		long long ans = 0;
		vector<long long> a(n);
		vector<pair<long long, long long>> mx(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mx[i].first = a[i] - n + i + 1;
			ans += a[i];
			mx[i].second = i + 1;
		}
		sort(mx.rbegin(), mx.rend());
		// cout << ans << '\n' ;
		for (int i = 0; i < k; i++)ans -= mx[i].first;
		// cout << ans << '\n';
		// for (int i = 0; i < k; i++)ans += n - mx[i].second;
		ans -= (long long)(k * (k - 1LL) / 2LL);
		cout << ans << '\n';
	}
	return 0;
}