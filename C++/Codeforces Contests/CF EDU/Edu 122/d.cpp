#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		ll n, k;
		cin >> n >> k;
		vector<ll> b(n), c(n), need(n, 0), st(10010, 1000000000);
		for (int i = 0; i < n; i++)cin >> b[i];
		for (int i = 0; i < n; i++)cin >> c[i];
		st[1] = 0, st[2] = 1;
		for (int i = 1; i < 10005; i++) {
			for (int j = 1; j * j <= i; j++) {
				if (i % j != 0)continue;
				int jj = i / j;
				if (i + j < 1000)st[i + j] = min(st[i + j], st[i] + 1);
				if (jj + i < 1000)st[jj + i] = min(st[i + jj], st[i] + 1);
			}
			if (i + i < 1000)st[i + i] = min(st[i + i], st[i] + 1);
		}
		// for (int i = 1; i <= 10; i++)cout << st[i] << ' ';
		for (int i = 0; i < n; i++) {
			b[i] = st[b[i]];
			// cout << b[i] << ' ';
		}
		vector<ll> dp(k + 1, 0);
		for (int i = 1; i < n + 1; i++) {
			for (int w = k; w >= b[i]; w--) {
				if (b[i - 1] <= w)
					dp[w] = max(dp[w], dp[w - b[i - 1]] + c[i - 1]);
			}
		}
		cout << dp[k] << '\n';
	}
	return 0;
}