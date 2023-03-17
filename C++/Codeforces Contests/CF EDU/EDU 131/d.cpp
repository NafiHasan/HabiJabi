#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool comp(pair<pair<int, int>, int> a , pair<pair<int, int>, int> b) {
	if (a.first.first == b.first.first)return b.first.second < a.first.second;
	return a.first.first < b.first.first;
}

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n + 1), ans(n + 1, -1);
		vector<pair<pair<int, int>, int>> vp;
		for (int i = 1; i <= n; i++)cin >> a[i];
		for (int i = 1; i <= n; i++) {
			int l, r;
			if (a[i] == 0) l = i + 1, r = n;
			else l = i / (a[i] + 1) + 1, r = i / a[i];
			vp.push_back({{r, l}, i});
		}
		sort(vp.begin(), vp.end(), comp);
		set<int> st;
		for (int i = 1; i <= n; i++) st.insert(i);
		for (int i = 0; i < vp.size(); i++) {
			int bg = *st.lower_bound(vp[i].first.second);
			ans[vp[i].second] = bg;
			st.erase(st.find(bg));
		}
		for (int i = 1; i <= n; i++)cout << ans[i] << ' ';
		cout << '\n';

	}
	return 0;
}