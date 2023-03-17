#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

double dp[505][505][2];
double n, p;
double fun(int game, int cur, int streak, int stat) {
	cout << game << ' ' << cur << ' ' << streak << ' ' << stat << '\n';
	if (dp[game][streak][stat] >= 0.0)return dp[game][streak][stat];
	if (game == n && stat == 1)return (double)(max(cur + 1, streak)) * p;
	if (game == n && stat == 0)return (double)streak * (double)(1.0 - p);

	double ans = 0;
	if (stat == 0) {
		streak = max(streak, cur);
		cur = 0;
		ans += fun(game + 1, cur , streak, 0);
		ans += fun(game + 1, cur , streak, 1);
		cout << ans << '\n';
		return dp[game][streak][0] = ans;
	} else {
		cur++;
		streak = max(streak, cur);
		ans += fun(game + 1, cur , streak, 0);
		ans += fun(game + 1, cur , streak, 1);
		cout << ans << '\n';
		return dp[game][streak][1] = ans;
	}
}



int main() {
	FastIO;
	while (1) {
		cin >> n >> p;
		if (n == 0)return 0;
		memset(dp, -1.0, sizeof dp);
		double ans = fun(1, 0, 0, 0) + fun(1, 0, 0, 1);
		cout << fixed << setprecision(10) << ans << '\n';
	}
	return 0;
}