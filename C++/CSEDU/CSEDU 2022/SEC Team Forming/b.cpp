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
	sieve();
	vector<long long> p;
	for (long long i = 2; i < N; i++) {
		if (prime[i])p.push_back(i);
	}
	// cout << p.size();
	// for (int i = 0; i < p.size(); i++)cout << p[i] << ' ';
	int n;
	cin >> n;
	vector<long long> a(n);
	map<long long, long long> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		// mp[a[i]]++;
	}
	sort(a.begin(), a.end());
	long long g = 1;
	for (int i = 0; i < n; i++) {
		// if (i && a[i] == a[i - 1])continue;
		// for (int j = 2; j < 1000005; j++) {
		// 	if (a[i] * j > a[n - 1])break;
		// 	if (mp[a[i] * j] > 0) {
		// 		g = 0;
		// 		break;
		// 	}
		// }
		for (int j = 0; j < p.size(); j++) {
			if (p[j] * p[j] > a[i])break;
			if (a[i] % p[j] == 0) {
				mp[p[j]]++;
				if (p[j] != (a[i] / p[j]))mp[a[i] / p[j]]++;
			}
			if (mp[p[j]] > 1)i = n + 1;
		}
	}
	for (int i = 0; i < p.size(); i++) {
		if (mp[p[i]] > 1)g = 0;
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