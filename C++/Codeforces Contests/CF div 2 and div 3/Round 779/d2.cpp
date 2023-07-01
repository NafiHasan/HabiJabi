#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int l, r;
		cin >> l >> r;
		int n = r - l + 1;
		vector<int> a(n), cnt(35, 0), fo(35, 0);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			for (int j = 0; j < 30; j++) {
				if (((1 << j) & a[i]) == 0)cnt[j]++;
			}
		}
		for (int i = l; i <= r; i++) {
			for (int j = 0; j < 30; j++) {
				if (((1 << j) & i) == 0)fo[j]++;
			}
		}
		int ans = 0;
		for (int i = 0; i < 30; i++) {
			if (cnt[i] > fo[i]) {
				ans |= (1 << i);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}