#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		int ans = n / k;
		int rem  = n - (ans * k);
		ans = min(rem, k / 2) + (ans * k);
		cout << ans << '\n';
	}
	return 0;
}