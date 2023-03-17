#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

ll nums(ll num, ll n, ll m) {
	ll cnt = 0;
	for (ll i = 1; i <= n; i++) {
		cnt += min(m, num / i);
	}
	return cnt;
}

ll div(ll num, ll n, ll m) {
	ll cnt = 0;
	for (ll i = 1; i * i <= num; i++) {
		if (num % i == 0) {
			if (i <= n && num / i <= m)cnt++;
			if (i != num / i && i <= m && num / i <= n)cnt++;
		}
	}
	return cnt;
}

int main() {
	FastIO;
	ll n, m , k;
	int f;
	f = 12;
	cin >> n >> m >> k;
	ll lo = 1, hi = n * m, mid, ans = 1;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		ll cnt = nums(mid, n, m);
		if (cnt < k) {
			lo = mid + 1;
		} else {
			ll d = div(mid, n, m);
			if (k <= (cnt - d)) {
				hi = mid - 1;
			} else {
				ans = mid;
				break;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}