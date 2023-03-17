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
		long long ans = 0, cnt = 0, need = n;
		while (n > 0) {
			if (n <= 6) {
				ans += 15;
				n -= 6;
			} else if (n % 6 == 0) {
				ans += (n / 6) * 15;
				n = 0;
			} else if (n <= 8) {
				ans += 20;
				n -= 8;
			} else if (n <= 10) {
				ans += 25;
				n -= 10;
			} else {
				cnt = (n / 10);
				ans += cnt * 25;
				n %= 10;
			}
		}
		cout << ans  << "\n";
	}
	return 0;
}