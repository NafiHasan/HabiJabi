#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 1000005;
vector<bool>prime(N + 1, 1);

void sieve() {
	prime[0] = prime[1] = 0;
	for (int i = 2; i * i <= N; i++) {
		if (!prime[i])continue;
		for (int j = i * i ; j <= N; j += i)prime[j] = 0;
	}
}


int main() {
	FastIO;
	sieve();
	vector<int> all;
	for (int i = 2; i < N; i++) {
		if (prime[i]) {
			all.push_back(i);
			// cout << i << ' ';
		}
	}
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		int st = -1, la = -2;
		for (int i = 0; i < all.size(); i++) {
			if (all[i] >= n && st == -1) {
				st = i;
			}
			if (all[i] <= m) {
				la = i;
			}
		}
		cout << la  - st + 1 << '\n';
	}
	return 0;
}