#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

long long mod = 1e9 + 7;

bool pal(long long i) {
	string s = to_string(i);
	string re = s;
	reverse(re.begin(), re.end());
	if (re == s)return 1;
	else return 0;
}
int main() {
	fast_io();
	int tc;
	cin >> tc;
	vector<long long> num;
	for (long long i = 1; i <= 40005; i++) {
		if (pal(i)) {
			num.push_back(i);
			// cout << i << ' ';
		}
	}
	long long N = 40005;
	long long dp[N + 1];

	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (long long i = 0; i < num.size(); i++) {
		for (long long j = 1; j <= N; j++) {
			if (j >= num[i]) {
				dp[j] += (dp[j - num[i]] % mod);
				dp[j] %= mod;
				// if (dp[j] > 1e18)cout << dp[j] << '\n';
			}
		}
	}

	while (tc--) {
		int n;
		cin >> n;
		long long anss = dp[n];
		// if (pal(n))anss++;
		cout << anss % mod << '\n';
	}
	return 0;
}