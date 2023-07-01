#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n;
	cin >> n;
	vector<long long> a(n), presum(n + 1, 0);
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < n; i++) {
		presum[i + 1] = presum[i] + a[i];
	}
	long long mx = 0;
	for (int i = 1; i <= n; i++) {
		long long divv = presum[i] / i;
		if (presum[i] % i != 0)divv++;
		mx = max(mx, divv);
	}
	int q;
	cin >> q;
	while (q--) {
		long long tm;
		cin >> tm;
		if (tm < mx)cout << "-1\n";
		else {
			long long divv = presum[n] / tm;
			if (presum[n] % tm != 0)divv++;
			cout << divv << '\n';
		}
	}
	return 0;
}