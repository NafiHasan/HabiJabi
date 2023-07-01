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
		int ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			ans |= a[i];
		}
		cout << ans << '\n';
	}
	return 0;
}