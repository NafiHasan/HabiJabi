#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 1005;
int d, k;
vector<vector<int>> dp(N, vector<int> (N, -1));
int fun(int a, int b) {
	if (a > b)swap(a, b);
	if (dp[a][b] != -1)return dp[a][b];
	if (a * a + b * b > d * d)return 0;
	int res = fun(a + k, b) + fun(a, b + k);
	res = !res;
	if (res == 1)dp[a][b] = 1;
	else dp[a][b] = 0;
	// cout << a << ' ' << b << ' ' << res << '\n';
	return dp[a][b];
}

int main() {
	fast_io();
	int tc;
	cin >> tc;
	d = 0;
	while (tc--) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)dp[i][j] = -1;
		}
		k = 1;
		d++;

		fun(0, 0);
		if (dp[0][0] == 0)cout << "A\n";
		else cout << "U\n";
	}
	return 0;
}