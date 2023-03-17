#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 200005;
vector<bool>prime(N + 1, 1);

void sieve() {
	prime[0] = prime[1] = 0;
	for (int i = 2; i * i <= N; i++) {
		if (!prime[i])continue;
		for (int j = i * i ; j <= N; j += i)prime[j] = 0;
	}
}

int main() {
	fast_io();
	sieve();
	vector<int> primes;
	for (int i = 2; i <= 200004; i++) {
		if (prime[i] == 1)primes.push_back(i);
	}
	int tc;
	cin >> tc;
	while (tc--) {
		int x, y, z;
		cin >> x >> y;
		z = (x ^ y);
		if (x % 2 == 0 && y % 2 == 1) {
			swap(x, y);
		}
		if (x % 2 == 0 && z % 2 == 1) {
			swap(x, z);
		}
		int a = 2, b = (2 ^ x);
		int c;
		if (z)c  = (2 ^ z);
		// bool prim = 1;
		// for (int i = 0; i < primes.size() ; i++) {
		// 	if (primes[i] * primes[i] > c)break;
		// 	if (c % primes[i] == 0) {
		// 		prim = 0; break;
		// 	}
		// }
		// if (prim == 0) {
		// 	b = (a ^ y);
		// 	c = (b ^ y);
		// }
		vector<int> all;
		all.push_back(a);
		all.push_back(b);
		all.push_back(c);
		sort(all.begin(), all.end());
		for (int i = 0; i < all.size(); i++)cout << all [i] << ' ';
		cout << '\n';

	}
	return 0;
}