#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define int long long

int h, g;
vector<pair<int, int>> hcows(1005), gcows(1005);
int dp[1005][1005];

int dist(pair<int, int> i, pair<int, int> j) {
	int d = abs(i.first - j.first) + abs(i.second - j.second);
	return (d * d);
}


// int f(int hind, int gind, pair<int, int> cur, int pre) {
// 	cout << hind <<  ' ' << gind << '\n';
// 	if (dp[hind][gind][pre] != -1)return dp[hind][gind][pre];
// 	if (hind == h - 1 && gind == g - 1)return 0;

// 	int ans = 1e18;
// 	// if (hind == h - 2 && gind <= g - 2) {
// 	// 	ans = min(ans, f(hind, gind + 1, gcows[gind + 1], 1) + dist(cur, gcows[gind + 1]));
// 	// 	ans = min(ans, f(hind, gind + 1, gcows[gind + 1], 0) + dist(cur, gcows[gind + 1]));
// 	// }
// 	// else {
// 	if (hind < h - 1)ans = min(f(hind + 1, gind, hcows[hind + 1], 0) + dist(cur, hcows[hind + 1]), ans);
// 	// if (hind < h - 1)ans = min(f(hind + 1, gind, hcows[hind + 1], 1) + dist(cur, hcows[hind + 1]), ans);
// 	if (gind < g - 1)ans = min(ans, f(hind, gind + 1, gcows[gind + 1], 1) + dist(cur, gcows[gind + 1]));
// 	// if (gind < g - 1)ans = min(ans, f(hind, gind + 1, gcows[gind + 1], 0) + dist(cur, gcows[gind + 1]));
// 	// }
// 	return dp[hind][gind][pre] = ans;
// }


signed main() {
	FastIO;
	// freopen("checklist.in", "r", stdin);
	// freopen("checklist.out", "w", stdout);
	cin >> h >> g;
	for (int i = 0; i < h; i++) cin >> hcows[i].first >> hcows[i].second;
	for (int i = 0; i < g; i++) cin >> gcows[i].first >> gcows[i].second;
	// memset(dp, 1e18, sizeof(dp));
	for (int i = 0; i <= h; i++) {
		for (int j = 0; j <= g; j++)dp[i][j] = 1e18;
	}
	// int ans = f(0, 0, hcows[0], 0);
	dp[0][0] = 0;
	for (int i = 0; i <= h; i++) {
		for (int j = 0; j <= g; j++) {
			if (i)dp[i][j] = min(dp[i][j], dp[i - 1][j] + dist(hcows[i - 2], hcows[i - 1]));
			if (j)dp[i][j] = min(dp[i][j], dp[i][j - 1] + dist(gcows[i - 2], gcows[i - 1]));
			if (i && j) {
				dp[i][j] = min(dp[i][j], min(dp[i - 1][j] + dist(hcows[i - 2], hcows[i - 1]), dp[i][j - 1] + dist(gcows[i - 2], gcows[i - 1])));
			}
		}
	}
	cout << dp[h][g] << '\n';
	return 0;
}