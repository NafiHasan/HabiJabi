#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int i = 0; i < n; i++)cin >> b[i];
		vector<pair<pair<int, int>, int>> ans(n);
		for (int i = 0; i < n; i++) {
			ans[i] = {{a[i] * b[i], b[i]}, -(i + 1)};
		}
		sort(ans.rbegin(), ans.rend());
		cout << -ans[0].second << '\n';
	}
	return 0;
}