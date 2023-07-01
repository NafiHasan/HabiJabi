#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	ll n, k, x;
	cin >> n >> k >> x;
	ll a[n];
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n);
	// vector<ll>final;
	// final.push_back(a[0]);
	int ans = 0, cnt = 0;
	// for (int i = 1; i < n; ) {
	// 	if (a[i] - final.back() > x && k > 0) {
	// 		final.push_back(final.back() + x);
	// 		k--;
	// 	} else final.push_back(a[i++]);
	// }
	// for (int i = 0; i < final.size(); i++)cout << final[i] << " ";
	// int prev = final[0];
	vector<ll>gap;
	for (int i = 1; i < n; i++) {
		if (a[i] - a[i - 1] > x) {
			cnt++;
			gap.push_back(a[i] - a[i - 1]);
		}
	}
	// if (cnt > 0)cnt++;
	// cout << cnt << en;
	sort(gap.begin(), gap.end());
	// for (int i = 0; i < gap.size(); i++)cout << gap[i] << " ";
	for (int i = 0; i < gap.size(); i++) {
		if (k == 0)break;
		ll need = gap[i] / x;
		if (gap[i] % x != 0)need++;
		need--;
		// cout << "s" << need << en;
		if (need <= k) {
			cnt--;
			// cout << need << " " << k << en;
			k -= need;
		}
	}
	cnt++;
	cout << cnt << en;
	return 0;
}