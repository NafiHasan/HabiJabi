#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >>  tc;
	while (tc--) {
		int a, b;
		cin >> a >> b;
		int win = (a + b + 1) / 2;
		vector<int>ans;
		for (int i = min(a, win); i >= 0; i--) {
			int lo = win - i;
			if (lo > b)continue;
			// ans.push_back(win-i);
			// cout << lo << "\n";
			int ad = win - i + a - i;
			ans.push_back(ad);
			ans.push_back(a + b - ad);
		}
		// for (int i = b; i >= 0; i--) {
		// 	int lo = win - i;
		// 	if (lo > a)continue;
		// 	ans.push_back(lo * 2);
		// }
		sort(ans.begin(), ans.end());
		vector<int> final;
		final.push_back(ans[0]);
		for (int i = 1; i < ans.size(); i++) {
			if (ans[i] != ans[i - 1])final.push_back(ans[i]);
		}
		cout << final.size() << "\n";
		for (int i = 0; i < final.size(); i++)cout << final[i] << ' ';
		cout << '\n';
	}
	return 0;
}