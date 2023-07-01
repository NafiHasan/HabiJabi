#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		long long n;
		cin >> n;
		vector<long long> a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		sort(a.begin(), a.end());
		bool ans = 0;
		long long sl = a[0] + a[1], sr = a[n - 1];
		if (sl < sr)ans = 1;
		for (int i = 2, j = n - 2; i < j; j--, i++) {
			sl += a[i];
			sr += a[j];
			if (sl < sr) {
				ans = 1;
				break;
			}
		}
		if (ans)cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}