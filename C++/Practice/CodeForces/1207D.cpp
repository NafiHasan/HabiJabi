#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const long long mod = 998244353;

int main() {
	fast_io();
	int n;
	cin >> n;
	vector<long long> fact(300010, 1LL);
	for (long long i = 2; i <= 300005; i++) fact[i] = (fact[i - 1] * i) % mod;
	vector<pair<long long, long long>> vp(n);
	for (int i = 0; i < n; i++) {
		cin >> vp[i].first >> vp[i].second;
	}
	sort(vp.begin(), vp.end());
	long long res = fact[n];
	long long ans = 1, cnt = 1;
	bool sor = 1;
	for (int i = 1; i < n; i++) {
		if (vp[i].first == vp[i - 1].first) {
			cnt++;
		} else {
			ans = ( ans * fact[cnt] ) % mod;
			cnt = 1;
		}
		if (vp[i].second < vp[i - 1 ].second)sor = 0;
	}
	ans = (ans * fact[cnt]) % mod;
	res = (res - ans + mod) % mod;
	cnt = 1;
	long long ans2 = 0;
	if (sor) {
		ans2 = 1LL;
		for (int i = 1; i < n; i++) {
			if (vp[i] == vp[i - 1]) {
				cnt++;
			} else {
				ans2 = ( ans2 * fact[cnt] ) % mod;
				cnt = 1;
			}
		}
		ans2 = (ans2 * fact[cnt]) % mod;
		cnt = 1;
		res = (res + ans2) % mod;
	}

	for (int i = 0; i < n; i++) {
		swap(vp[i].first, vp[i].second);
	}
	sort(vp.begin(), vp.end());
	long long ans3 = 1LL;
	for (int i = 1; i < n; i++) {
		if (vp[i].first == vp[i - 1].first) {
			cnt++;
		} else {
			ans3 = ( ans3 * fact[cnt] ) % mod;
			cnt = 1;
		}
	}
	ans3 = (ans3 * fact[cnt]) % mod;
	res = (res - ans3 + mod) % mod;
	cout << res << '\n';
	return 0;
}