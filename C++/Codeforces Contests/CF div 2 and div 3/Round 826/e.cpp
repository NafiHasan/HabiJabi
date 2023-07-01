#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n;
vector<int> a(200005);
int dp[200005];

bool f(int ind) {
	// cout << ind << '\n';
	if (ind + a[ind] + 1 == n)return 1;
	if (ind == n) return 1;
	if (ind > n) return 0;
	if (dp[ind] != -1) {
		if (dp[ind] == 0) return 0;
		else return 1;
	}
	bool pos = 0;
	if ((ind + a[ind] + 1) < n)pos |= f(ind + a[ind] + 1);
	if (pos) {
		dp[ind] = 1;
		return 1;
	}
	int cnt = 1;
	for (int i = ind + 1; i < n; i++) {
		if (a[i] == cnt && f(i + 1)) {
			dp[i] = 1;
			return 1;
		}
		cnt++;
	}
	dp[ind] = 0;
	return 0;
}




int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		if (f(0))cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}