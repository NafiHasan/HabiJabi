#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >>t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"

const int lim = 1000005;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll dp[1000005];
	memset(dp, 0, sizeof(dp));
	bool prime[lim];
	int limit = sqrt(1000005) + 1;
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i <= limit; i++) {
		if (prime[i] == true) {
			for (int j = i * i; j < lim; j += i)
				prime[j] = false;
		}
	}
	vector<int> v;
	for (int i = 2; i < lim; i++)
		if (prime[i] == true)
			v.push_back(i);
	int dif = 0;
	for (int i = 1; i < v.size(); i++) {
		dif = max(dif, v[i] - v[i - 1]);
	}
	cout << dif << '\n';
	int T;
	// cin >> T;
	T = 0;
	while (T--) {
		int n;
		cin >> n;
		if (dp[n] > 0) cout << dp[n] << en;
		else if (prime[n] == true) cout << n << en;
		else {
			int best = INT_MAX, dif = INT_MAX;
			int mid, lo = 0, hi = v.size() - 1;
			while (lo <= hi) {
				mid = lo + (hi - lo) / 2;
				if (v[mid] == n && prime[v[mid]] == true) {
					best = v[mid];
					break;
				} else if (v[mid] < n) {
					if (dif > (abs(v[mid] - n)) && prime[v[mid]] == true) {
						best = v[mid];
						dif = abs(v[mid] - n);
					}
					lo = mid + 1;
				} else {
					if (dif > (abs(v[mid] - n)) && prime[v[mid]] == true) {
						best = v[mid];
						dif = abs(v[mid] - n);
					}
					hi = mid - 1;
				}
				//cout <<v[mid]<<" ";
			}
			dp[n] = best;
			cout << best << en;
		}
	}
	return 0;
}