#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


int main() {
	FastIO;
	int items, total_weight;
	cin >> items >> total_weight;

	vector<vector<int>> dp(items + 5, vector<int> (total_weight + 5, 0));
	vector<int> weight(items), value(items);
	for (int i = 0; i < items; i++)cin >> weight[i] >> value[i];

	for (int i = 1; i <= items; i++) {
		for (int j = 1; j <= total_weight; j++) {
			if (weight[i] <= j) {
				dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i]], dp[i - 1][j]);
			} else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[items][total_weight] << '\n';
	return 0;
}










// //with memo
// const int N = 1000;

// int value[N], weight[N], items, total_weight;

// int dp[N][N];
// int knapsack(int remaining_weight, int index) {
// 	if (dp[remaining_weight][index] != -1)return dp[remaining_weight][index];
// 	if (remaining_weight <= 0)return 0;
// 	if (index >= items)return 0;
// 	if (remaining_weight < weight[index])return dp[remaining_weight][index] = knapsack(remaining_weight, index + 1);

// 	return dp[remaining_weight][index] = max(knapsack(remaining_weight, index + 1), knapsack(remaining_weight - weight[index], index + 1) + value[index]);
// }



// int main() {
// 	FastIO;
// 	memset(dp, -1, sizeof(dp));
// 	cin >> items >> total_weight;
// 	for (int i = 0; i < items; i++)cin >> weight[i] >> value[i];
// 	int ans = knapsack(total_weight, 0);
// 	cout << ans << '\n';
// 	return 0;
// }










// without memo
// const int N = 100;

// int value[N], weight[N], items, total_weight;

// int knapsack(int remaining_weight, int index) {
// 	if (remaining_weight <= 0)return 0;
// 	if (index >= items)return 0;
// 	if (remaining_weight < weight[index])return knapsack(remaining_weight, index + 1);

// 	return max(knapsack(remaining_weight, index + 1), knapsack(remaining_weight - weight[index], index + 1) + value[index]);
// }



// int main() {
// 	FastIO;
// 	cin >> items >> total_weight;
// 	for (int i = 0; i < items; i++)cin >> weight[i] >> value[i];
// 	int ans = knapsack(total_weight, 0);
// 	cout << ans << '\n';
// 	return 0;
// }
// test :
// 5 10
// 2 1
// 3 7
// 5 6
// 5 6
// 4 8