#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 1000005;
vector<bool>prime(N + 1, 1);

void sieve() {
	prime[0] = prime[1] = 0;
	for (long long i = 2; i * i <= N; i++) {
		if (!prime[i])continue;
		for (int j = i * i ; j <= N; j += i)prime[j] = 0;
	}
}


int main() {
	fast_io();
	// sieve();
	// vector<long long> p;
	// for (long long i = 2; i < N; i++) {
	// 	if (prime[i])p.push_back(i);
	// }
	// cout << p.size();
	// for (int i = 0; i < p.size(); i++)cout << p[i] << ' ';
	int n;
	cin >> n;
	vector<long long> a(n);
	map<long long, long long> mp;
	map<long long, long long> dp;
	long long g = 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[a[i]]++;
		if (a[i] > 1 && dp[a[i]] > 1)g = 0;
		// mp[a[i]]++;
	}
	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++) {
		mp[a[i]]++;
		for (long long j = 2; j * j <= a[i]; j++) {
			// cout << a[i] << ' ' << j << '\n';
			if (a[i] % j == 0) {
				mp[j]++;
				if (mp[j] > 1) {
					i = n + 1;
					break;
				}
				if (j != (a[i] / j)) {
					mp[a[i] / j]++;
					if (mp[a[i] / j] > 1) {
						i = n + 1;
						break;
					}
				}
			}
		}
	}
	for (int i = 2; i <= a[n - 1] ; i++) {
		if (mp[i] > 1) {
			g = 0;
			break;
		}
	}
	if (g == 1) {
		cout  << "pairwise coprime\n";
		return 0;
	} else {
		g = a[0];
		for (int i = 1; i < n; i++)g = __gcd(g, a[i]);
		if (g == 1) {
			cout << "setwise coprime\n";
			return 0;
		} else cout << "not coprime\n";
	}
	return 0;
}