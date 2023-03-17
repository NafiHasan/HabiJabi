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
		sum += a[i];
	}
	sort(a.begin(), a.end());
	ll ans = sum * n * 2LL;
	ll cnt = n * n - m;
	ll cnt0 = sqrt(cnt);
	ll tmpsum = 0;
	for (int i = 0; i < cnt0; i++) {
		tmpsum += a[i];
	}
	cout << tmpsum << ' ' << cnt0 << '\n';
	tmpsum *= cnt0 * 2LL;
	ans -= tmpsum;
	cnt -= cnt0 * cnt0;
	cout << cnt << '\n';
	vector<ll> sub;
	for (int i = 0; i < min(n, 10000LL); i++) {
		for (int j = cnt0; j < min(10000LL, n); j++) {
			sub.push_back(a[i] + a[j]);
		}
	}
	ll minus = LLONG_MAX, got = 0;
	sort(sub.begin(), sub.end());
	ll tmpcnt = cnt;
	for (int i = 0; i < sub.size() && tmpcnt > 0; i++) {
		tmpcnt--;
		got += sub[i];
		if (tmpcnt > 0) {
			got += sub[i];
			tmpcnt--;
		}
	}
	minus = min(minus, got);
	sub.clear();
	for (int i = 0; i < min(n, 100000LL); i++) {
		for (int j = cnt0; j < min(n, 1000LL); j++) {
			sub.push_back(a[i] + a[j]);
		}
	}
	sort(sub.begin(), sub.end());

	got = 0;
	tmpcnt = cnt;
	for (int i = 0; i < sub.size() && tmpcnt > 0; i++) {
		tmpcnt--;
		got += sub[i];
		if (tmpcnt > 0) {
			got += sub[i];
			tmpcnt--;
		}
	}
	minus = min(minus, got);

	ans -= minus;

	cout << ans << '\n';
	return 0;
}