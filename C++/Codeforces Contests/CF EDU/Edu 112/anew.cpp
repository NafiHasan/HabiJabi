#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		long long n ;
		cin >> n;
		long long ans = 0;
		if (n <= 6)ans = 15;
		else {
			if (n % 2)n++;
			ans = (n / 2LL) * 5LL;
		}
		cout << ans << "\n";
	}
	return 0;
}