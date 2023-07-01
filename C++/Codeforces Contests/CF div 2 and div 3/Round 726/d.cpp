#include <bits/stdc++.h>

using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int mx = 10000000;
	vector<bool>primes(mx + 1, 1);
	for (int i = 2; i * i <= mx; i++) {
		if (primes[i] == 0)continue;
		for (int j = i * i; j <= mx; j += i)primes[j] = 0;
	}
	int tc;
	cin >> tc ;
	while (tc--) {
		int n;
		cin >> n;
		int win = 0;
		while (primes[n] == 0) {
			win = 1 - win;
			if (n % 2 == 0 && primes[n / 2] == 1)n /= 2;
			else {
				bool found = 0;
				for (int i = 2; i * i <= n; i++) {
					if (n % i == 0 && primes[(n - i) / 2] == 0) {
						n -= i;
						found = 1;
						break;
					}
				}
				if (!found) {
					cout << n << "\n";
					// win = 1 - win;
					break;
				}
			}
		}
		if (win) cout << "Alice\n";
		else cout << "Bob\n";
	}
	return 0;
}