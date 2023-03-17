#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// top down
int n, sum;
int coin[105], dp[105];


int main() {
	FastIO;
	cin >> n >> sum;
	for (int i = 0; i < n; i++)cin >> coin[i];
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= sum; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}
	cout << dp[sum] << '\n';
	return 0;
}










// without memo
// int n, sum;
// int coin[105];
// int way(int val, int last) {
// 	if (val == 0)return 1;
// 	if (val < 0)return 0;

// 	int ans = 0;
// 	for (int i = last; i < n; i++) {
// 		if (val - coin[i] <= sum )ans += way(val - coin[i], i);
// 	}
// 	return ans;
// }


// int main() {
// 	FastIO;
// 	cin >> n >> sum;
// 	for (int i = 0; i < n; i++)cin >> coin[i];
// 	sort(coin, coin + n);
// 	cout << way(sum, 0) << '\n';
// 	return 0;
// }





// // with memo
// int n, sum;
// int coin[105];
// int dp[105];
// int way(int val, int last) {

// 	if (val == 0)return dp[val] = 1;
// 	if (val < 0)return dp[val] = 0;
// 	if (dp[val] != -1)return dp[val];
// 	int ans = 0;
// 	for (int i = last; i < n; i++) {
// 		if (val - coin[i] <= sum )ans += way(val - coin[i], i);
// 	}
// 	return dp[val] = ans;
// }


// int main() {
// 	FastIO;
// 	cin >> n >> sum;
// 	memset(dp, -1, sizeof(dp));
// 	for (int i = 0; i < n; i++)cin >> coin[i];
// 	sort(coin, coin + n);
// 	cout << way(sum, 0) << '\n';
// 	return 0;
// }