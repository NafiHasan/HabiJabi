#include<bits/stdc++.h>
using namespace std;

// #include "debug.h"

using ll = long long;

void solve() {
	ll n, k;  cin >> n >> k;
	vector<ll> a(n);
	for (auto &ai : a) {
		cin >> ai;
	}

	ll sum = 0, sum_ab = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		for (int j = i + 1; j < n; ++j) {
			sum_ab += a[i] * a[j];
		}
	}

	if (sum != 0) {
		if (sum_ab % sum == 0) {
			cout << -(sum_ab / sum) << "\n";
		} else {
			if (k != 1) {
				ll x = -sum_ab + sum * sum;
				cout << (1 - sum) << " " << (x - sum) << "\n";
			} else {
				cout << "IMPOSSIBLE\n";
			}
		}
	} else {
		if (sum_ab == 0) {
			cout << "0\n";
		} else {
			if (k != 1) {
				ll x = -sum_ab + sum * sum;
				cout << (1 - sum) << " " << (x - sum) << "\n";
			} else {
				cout << "IMPOSSIBLE\n";
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int tt;  cin >> tt;
	for (int t = 1; t <= tt; ++t) {
		cout << "Case #" << t << ": ";
		solve();
	}
}

