#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n);
		int ans = 0, prev = 0;
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int i = 0; i < n; i++) {
			if (a[i] != 0 && prev == 0)ans++;
			prev = a[i];
		}
		ans = min(2, ans);
		cout << ans << '\n';
	}
	return 0;
}