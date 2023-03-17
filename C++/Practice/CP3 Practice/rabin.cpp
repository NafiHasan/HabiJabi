#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<int> rk(string s, string p) {
	const int po = 31;
	const int mod = 1e9 + 9;
	int n = s.size(), m = p.size();
	vector<long long> p_pow(max(n, m));
	p_pow[0] = 1;
	for (int i = 1; i < (int)p_pow.size(); i++)
		p_pow[i] = (p_pow[i - 1] * po) % mod;

	vector<long long> hsh(n + 1, 0);
	for (int i = 0; i < n; i++)
		hsh[i + 1] = (hsh[i] + (s[i] - 'a' + 1) * p_pow[i]) % mod;

	long long fhash = 0;
	for (int i = 0; i < m; i++)
		fhash = (fhash + (p[i] - 'a' + 1) * p_pow[i]) % mod;

	vector<int> ind;
	for (int i = 0; i + m - 1 < n; i++) {
		long long curhash = (hsh[i + m] + mod - hsh[i]) % mod;
		if (curhash == fhash  * p_pow[i] % mod)
			ind.push_back(i);
	}
	return ind;
}



int main() {
	FastIO;

	return 0;
}