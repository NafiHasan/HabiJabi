#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		long long n, s;
		cin >> n >> s;
		long long ans = 0, sum = 0;
		// while (s >= (n * n)) {
		// 	s -= (n * n);
		// 	ans++;
		// }
		ans = s / (n * n);
		cout << ans << '\n';
	}
	return 0;
}