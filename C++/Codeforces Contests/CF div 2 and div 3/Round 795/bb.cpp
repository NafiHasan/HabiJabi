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
		int mn = INT_MAX, ans = 0, even = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] % 2 == 0)even++;
			int tmp = a[i], cnt = 0;
			while (tmp > 0 && tmp % 2 == 0) {
				cnt++;
				tmp /= 2;
			}
			mn = min(mn, cnt);
		}
		if (mn == 0) {
			ans = even;
		} else {
			ans = mn + even - 1;
		}
		cout << ans << '\n';
	}
	return 0;
}