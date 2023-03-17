#include <bits/stdc++.h>
#pragma
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<bool> cl(n, 0);
		vector<int> sum(n + 5, 0);
		for (int i = 0; i < n; i++) {
			int l, r;
			cin >> l >> r;
			l--, r--;
			sum[l + 1]++;
			sum[r + 2]--;
			if (l <= i && i <= r) cl[i] = 1;
		}
		for (int i = 1; i <= n; i++)sum[i] += sum[i - 1];
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			// long long cnt = query(1, 0, n - 1, i, i, 0);
			if (sum[i + 1] == (n - 1) && cl[i] == 0)ans.push_back(i + 1);
		}
		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++)cout << ans[i] << '\n';
	}
	return 0;
}