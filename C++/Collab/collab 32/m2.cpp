#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long


int main() {
	FastIO;
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	ll cnt = sqrt(m);
	for (int i = 0 ; i < cnt ; i++) {
		sum += a[i];
	}
	sum *= cnt * 2LL;
	ll rem = m - (cnt * cnt);
	cout << sum << '\n';
	// cnt = rem;
	// cout << rem << '\n';
	// reverse(a.begin(), a.end());
	vector<ll> sub;
	for (int i = 0; i < min(n, 10000LL); i++) {
		for (int j = cnt; j < min(10000LL, n); j++) {
			sub.push_back(a[i] + a[j]);
			cout << a[i]  << ' ' <<  a[j] << '\n';
		}
	}
	ll minus = 0, got = 0;
	sort(sub.rbegin(), sub.rend());
	for (int i = 0; i < sub.size(); i++) {
		cout << sub[i] << ' ';

	}
	ll tmpcnt = rem;
	for (int i = 0; i < sub.size() && tmpcnt > 0; i++) {
		tmpcnt--;
		got += sub[i];
		if (tmpcnt > 0) {
			got += sub[i];
			tmpcnt--;
		}
	}
	minus = max(minus, got);
	sub.clear();
	for (int i = 0; i < min(n, 100000LL); i++) {
		for (int j = cnt; j < min(n, 1000LL); j++) {
			sub.push_back(a[i] + a[j]);
		}
	}
	sort(sub.rbegin(), sub.rend());

	got = 0;
	tmpcnt = rem;
	for (int i = 0; i < sub.size() && tmpcnt > 0; i++) {
		tmpcnt--;
		got += sub[i];
		if (tmpcnt > 0) {
			got += sub[i];
			tmpcnt--;
		}
	}
	minus = max(minus, got);
	cout << minus << ' ' << cnt << '\n';
	sum += minus;

	cout << sum << '\n';
	return 0;
}