#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const long long mod = 1e9 + 7;

int main() {
	FastIO;
	int n;
	cin >> n;
	vector<long long> a(n);
	map<long long, long long> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	sort(a.begin(), a.end());
	vector<long long> dp(n + 1, 1);
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (a[i] % a[j] == 0 && mp[a[i] / a[j]] > 0) {
				int lo = 0, hi = j, mid, ind = -1;
				while (lo <= hi) {
					mid = (lo + hi) / 2;
					if (a[mid] < a[i] / a[j])lo = mid + 1;
					else if (a[mid] > a[i] / a[j])hi = mid - 1;
					else {
						ind = mid;
						break;
					}
				}
				if (ind == -1)continue;
				dp[i] += dp[j];
				dp[i] %= mod;
				dp[i] += dp[ind];
				dp[i] %= mod;
				cout << i << ' ' << j << ' ' << ind << ' ' << dp[i] << ' ' << dp[j] << '\n';
			}
		}
	}
	cout << dp[n - 1] << '\n';
	return 0;
}