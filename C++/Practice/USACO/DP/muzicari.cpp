#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


int dp[5005][505], a[505], res[505], pre[505];
int T, n;

int func(int t, int ind, int rem1, int rem2) {
	cout << t << ' ' << ind << ' ' << rem1 << ' ' << rem2 << '\n';
	if (dp[t][ind] != -1) {
		return dp[t][ind];
	}
	if (ind == n)return dp[t][ind] = 1;
	rem1 = max(0, rem1); rem2 = max(0, rem2);
	int ans = 0;
	for (int i = ind; i < n; i++) {
		if (t + a[i] <= T && rem1 == 0) {
			ans |= func(t, ind + 1, rem1 + a[i] - 1, rem2 - 1);

		} else if (t + a[i] <= t && rem2 == 0) {
			ans |= func(t, ind + 1, rem1 - 1, rem2 + a[i] - 1);
		}
	}
	if (rem1 > 0 && rem2 > 0) {
		ans |= func(t + 1, ind, rem1 - 1, rem2 - 1);
	}

	if (ans == 1)res[ind] = t;
	return dp[t][ind] = ans;
}


int main() {
	FastIO;
	cin >> T >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	memset(dp, -1, sizeof(dp));
	memset(res, -1, sizeof(res));
	func(0, 0, 0, 0);
	for (int i = 0; i < n; i++)cout << res[i] << ' ';
	cout << '\n';
	return 0;
}