#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<pair<int, int>> a(n);
		for (int i = 0; i < n; i++)cin >> a[i].first;
		for (int i = 0; i < n; i++)cin >> a[i].second;
		vector<pair<int, int>> ans;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[i].first >= a[j].first && a[i].second >= a[j].second) {
					swap(a[i], a[j]);
					ans.push_back({i + 1, j + 1});
				}
			}
		}
		bool an = 1;
		for (int i = 1; i < n; i++) {
			if (a[i].first < a[i - 1].first)an = 0;
			if (a[i].second < a[i - 1].second)an = 0;
		}
		if (an) {
			cout << ans.size() << '\n';
			for (int i = 0; i < ans.size(); i++)cout << ans[i].first << ' ' << ans[i].second << '\n';
		} else cout  << "-1\n";
	}
	return 0;
}