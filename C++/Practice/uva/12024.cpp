#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<int> dp(15, -1);

int d(int n) {
	if (dp[n] != -1)return dp[n];
	if (n == 1)return 0;
	if (n == 2)return 1;
	return (n - 1) * (d(n - 1) + d(n - 2));
}

int fact(int n) {
	int ans = 1;
	for (int i = 2; i <= n; i++)ans *= i;
	return ans;
}

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		cout << d(n) << "/" << fact(n) << '\n';
	}
	return 0;
}