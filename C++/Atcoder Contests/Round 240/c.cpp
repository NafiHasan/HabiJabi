#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n, x;
	cin >> n >> x;
	vector<int> coin(n);
	int mn = 0, mx = 0;
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		mn += u, mx += v;
		coin[i] = v - u;
	}
	if (x > mx || x < mn) {
		cout << "No\n";
		return 0;
	}
	int need = x - mn;
	vector<int> dp(need + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = need; j >= 1; j--) {
			if (j >= coin[i] && dp[j - coin[i]])dp[j] = 1;
		}
	}
	if (dp[need])cout << "Yes\n";
	else cout << "No\n";
	return 0;
}