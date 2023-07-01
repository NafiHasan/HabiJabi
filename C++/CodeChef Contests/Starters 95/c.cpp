#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

long long mod = 1e9 + 7;

long long bigmod (long long a, long long n) {
	a %= mod;
	long long ans = 1;
	while (n) {
		if (n & 1) ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans;
}

int dp[505][505][505];
int n, k;
vector<int> a(505), presum(505);
string s;
int cnt = 0;
int f(int st, int en, int ind) {
	cnt++;
	cout << st << ' ' << en << ' ' << ind << '\n';

	if (dp[st][en][ind] != -1)return dp[st][en][ind];
	int div = (en - st);
	int sum = 0;
	if (s[ind] == 'L') {
		for (int i = st; i < en; i++) {
			if (ind < k - 1 && st < i)sum += f(st, i, ind + 1);
			else sum += presum[i + 1] - presum[st];
			sum %= mod;
		}
	} else {
		for (int i = st + 1; i <= en; i++) {
			if (ind < k - 1 && i < en)sum += f(i, en, ind + 1);
			else sum += presum[en + 1] - presum[i];
			sum %= mod;
		}
	}
	// cout << st << ' ' << en << ' ' << div << ' ' << ind << '\n';
	return dp[st][en][ind] = sum * bigmod(div, mod - 2) % mod;
}


int32_t main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++)cin >> a[i];
		presum[0] = 0;
		cin >> s;

		memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			presum[i] = presum[i - 1] + a[i - 1];
		}


		cout << f(0, n - 1, 0) << '\n';
		cout << cnt << '\n';
	}
	return 0;
}