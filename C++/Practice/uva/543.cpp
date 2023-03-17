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
	// cout << primes[(int)primes.size() - 1] << '\n';
	while (1) {
		int n;
		cin >> n;
		if (n == 0)break;
		int a = -1, b = -1;
		bool f = 1;
		for (int i = 0; i < (int)primes.size() && f; i++) {
			int lo = 0, hi = primes.size() - 1, mid, need = n - primes[i];
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (primes[mid] == need) {
					a = primes[i], b = primes[mid];
					f = 0;
					break;
				} else if (primes[mid] < need) lo = mid + 1;
				else hi = mid - 1;
			}
		}
		cout << n << " = " << a << " + " << b << '\n';
	}
	return 0;
}