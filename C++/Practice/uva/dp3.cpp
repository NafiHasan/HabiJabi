#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int dp[1000005], n;

int f(int num) {
	// cout << num << '\n';

	if (dp[num] != -1)return dp[num];
	if (num == 0)return dp[num] = 0;
	if (num < 10)return dp[num] = 1;

	string s = to_string(num);
	// cout << s  << '\n';
	int ans = n + 1, cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0')continue;
		int numb = s[i] - '0';
		ans = min(ans, 1 + f(num - numb));
	}

	return dp[num] = ans;
}


signed main() {
	FastIO;
	cin >> n;
	memset(dp, -1, sizeof dp);
	cout << f(n) << '\n';
	return 0;
}