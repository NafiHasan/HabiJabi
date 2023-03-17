#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// vector<long long> fib(1005, 0);
// vector<long long> ff() {

// 	return fib;
// }


int main() {
	fast_io();
	// fib[1] = 2, fib[2] = 3;
	// for (int i = 3; i < 1005; i++) {
	// 	fib[i] = fib[i - 1] + fib[i - 2];
	// }
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<long long> f(n + 1);
		for (int i = 1; i <= n; i++)cin >> f[i];
		// int f[1005];
		// for (int i = 1; i < 10; i++) {
		// 	f[i] = fib[i];
		// 	// cout << f[i] <<  ' ';
		// }
		// cout << "\n";
		long long ans = 0;
		for (int i = 1; i < n; i++) {
			long long sum = (f[i] + f[i + 1]);
			ans += sum / 3;
			sum %= 3;
			f[i + 1] = min(f[i + 1], sum);
		}
		cout << ans << '\n';
	}
	return 0;
}