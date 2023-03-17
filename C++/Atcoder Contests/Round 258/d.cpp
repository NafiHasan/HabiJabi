#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n, x;
	cin >> n >> x;
	vector<pair<long long, long long> >a(n);
	vector<long long> presum(n + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		presum[i + 1] = presum[i] + a[i].first + a[i].second;
	}
	vector<long long> dp(n, LLONG_MAX);
	for (int i = 0; i < n; i++) {
		if (i > x)continue;
		dp[i] = min(dp[i], presum[i + 1] + (x - i - 1) * a[i].second);
	}
	long long ans = *min_element(dp.begin(), dp.end());
	cout << ans << '\n';
	return 0;
}