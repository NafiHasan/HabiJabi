#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n , k;
		cin >> n >> k;
		// multiset<int> st;
		vector<int> ed[k + 1], a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			ed[a[i] % k].push_back(a[i]);
		}
		long long ans = 0;
		for (int i = k - 1; i >= 0; i--) {
			if (ed[i].size() == 0)continue;
			if (ed[k - i].size() == 0)continue;
			if (i != (k - i)) {
				ans += (ed[i].back() + ed[k - i].back()) / k;
				ed[i].pop_back();
				ed[k - i].pop_back();
			} else {
				if (ed[i].size() < 2)continue;
				int t1 = ed[i].back();
				ed[i].pop_back();
				int t2 = ed[i].back();
				ans += (t1 + t2) / k;
				ed[i].pop_back();
			}
		}
		int left = -1;
		for (int i = k - 1; i >= 0; i--) {
			if (ed[i].size() == 1) {
				if (left == -1) {
					left = ed[i].back();
					ed[i].pop_back();
				} else {
					ans += (left + ed[i].back()) / k;
					ed[i].pop_back();
					left = -1;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}