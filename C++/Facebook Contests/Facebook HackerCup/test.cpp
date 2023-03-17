#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define int long long
const int N = 10000010;
// vector<bool>prime(N + 1, 1);
bitset<10000010> prime;
vector<int> primes;

void sieve() {
	prime.set();
	prime[0] = prime[1] = 0;
	for (int i = 2; i * i <= N; i++) {
		cout << i << '\n';
		if (!prime[i])continue;
		for (int j = i * i ; j < N; j += i)prime[j] = 0;
	}
	for (int i = 2; i < N; i++)if (prime[i])primes.push_back(i);
}

signed main() {
	FastIO;
	sieve();
	// for (int i = 0; i < primes.size(); i++)cout << primes[i] << '\n';
	return 0;
}