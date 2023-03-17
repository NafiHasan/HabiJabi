#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 10000010;
bitset < N + 5 > bs;
vector<int> primes;

void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i * i <= N; i++) {
		if (!bs[i])continue;
		for (int j = i * i ; j <= N; j += i)bs[j] = 0;
	}
	for (int i = 2; i <= N; i++)if (bs[i])primes.push_back(i);
}



int main() {
	FastIO;
	sieve();
	while (1) {
		int l, r;
		cin >> l >> r;
		if (cin.eof())break;
		int mn = 100000000, mx = 0, c1 = -1, c2 = -1, d1 = -1, d2 = -1;
		for (int i = 0; i < primes.size() - 1; i++) {
			if (primes[i] < l)continue;
			if (primes[i + 1] > r)break;
			if ((primes[i + 1] - primes[i]) < mn) {
				mn = primes[i + 1] - primes[i];
				c1 = primes[i], c2 = primes[i + 1];
			}
			if (primes[i + 1] - primes[i] > mx) {
				mx = primes[i + 1] - primes[i];
				d1 = primes[i], d2 = primes[i + 1];
			}
		}
		if (c1 == -1) {
			cout << "There are no adjacent primes.\n";
		} else {
			cout << c1 << "," << c2 << " are closest, " << d1 << "," << d2 << " are most distant.\n";
		}

	}
	return 0;
}