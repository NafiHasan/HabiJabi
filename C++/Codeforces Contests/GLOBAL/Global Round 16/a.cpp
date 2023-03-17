#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, s;
		cin >> n >> s;
		int div = n / 2 + 1;
		int ans = s / div;
		cout << ans << '\n';
	}
	return 0;
}