#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, z;
		cin >> n >> z;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			ans = max(ans, (x | z));
		}
		cout << ans << '\n';
	}
	return 0;
}