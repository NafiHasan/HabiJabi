#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin  >> a[i];
			a[i] = a[i] - i;
		}
		map<int, int>m;
		for (int i = 0; i < n; i++) {
			m[a[i]]++;
		}
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			long long x = m[a[i]];
			m[a[i]] = -1;
			if (x != -1)ans += x * (x - 1) / 2;
		}
		cout << ans << en;
	}
	return 0;
}