#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a.begin(), a.end());
	vector<bool> dp(100005, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 100005; j >= a[i]; j--) {
			// reverse order because we don't want to count any coin twice for same sum
			if (dp[j - a[i]] != 0) dp[j] = 1;
		}
	}
	vector<int> ans;
	for (int i = 1; i <= 100005; i++)if (dp[i] == 1)ans.push_back(i);
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)cout << ans[i] << ' ' ;
	cout << '\n';
	return 0;
}