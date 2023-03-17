
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector <long long> a(n); for (auto &x : a) cin >> x;
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			if (!a[i]) continue;
			if (a[i] % 2) ans ^= n - 1 - i;
		}
		cout << (ans ? "Chef\n" : "Cook\n");
	}
}