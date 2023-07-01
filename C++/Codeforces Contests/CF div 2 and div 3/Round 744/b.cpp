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
		vector<int>v(n);
		for (int i = 0; i < n ; i++)cin >> v[i];
		vector<int>sorted(n);
		sorted = v;
		vector<pair<pair<int, int>, int>>ans;
		sort(sorted.begin(), sorted.end());
		for (int i = 0; i < n; i++) {
			if (sorted[i] == v[i]) continue;
			int l = i + 1 , r, sh;
			for (int j = i + 1; j < n; j++) {
				if (v[j] == sorted[i]) {
					r = j + 1;
					break;
				}
			}
			ans.push_back({{l, r}, r - l});
			sh = r - l;
			vector<int>ne(sh + 1);
			ne[0] = v[r - 1];
			for (int j = 1; j <= sh; j++)ne[j] = v[l - 1 + j - 1];
			for (int j = l - 1, k = 0; j < r; j++, k++)v[j] = ne[k];
		}
		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++)cout << ans[i].first.first << ' ' << ans[i].first.second << ' ' << ans[i].second << '\n';
	}
	return 0;
}