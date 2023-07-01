#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
int main() {
	fast_io();
	int n, q;
	cin >> n >> q;
	vector<	ll> a(n);
	ll sum = 0, now = -1;
	for (int i = 0; i < n; i++) {
		cin >> a [i];
		sum += a[i];
	}
	set<ll> st;
	while (q--) {
		ll t, ind, x;
		cin >> t;
		if (t == 1)cin >> ind >> x;
		else cin >> x;
		if (t == 1) {
			if (st.find(ind) != st.end()) {
				// if (now != -1)sum += x - now;
				// else {
				sum += x - a[ind - 1];
				// }
				a[ind - 1] = x;
			} else {
				if (now != -1)sum += x - now;
				else {
					sum += x - a[ind - 1];
				}
				a[ind - 1] = x;
				st.insert(ind);
			}
			cout << sum << '\n';
		} else {
			sum = x * n;
			now = x;
			st.clear();
			cout << sum << '\n';
		}
	}
	return 0;
}