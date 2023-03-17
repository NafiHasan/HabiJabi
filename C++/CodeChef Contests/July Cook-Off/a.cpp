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
		int ans = n % 3;
		if (ans != 0)ans = 3 - ans;
		cout << ans << '\n';
	}
	return 0;
}