#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define int long long

int lcm(int a, int b) {
	return a * b / __gcd(a, b);
}


signed main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		b[0] = a[0];
		b[n] = a[n - 1];
		for (int i = 1; i < n; i++) {
			b[i] = lcm(a[i], a[i - 1]);
		}
		bool ok = 1;
		for (int i = 0; i < n; i++) {
			if (a[i] != __gcd(b[i], b[i + 1]))ok = 0;
		}
		if (ok)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}