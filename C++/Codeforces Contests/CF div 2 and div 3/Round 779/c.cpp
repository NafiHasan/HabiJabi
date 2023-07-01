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
		vector<pair<int, int>> vp(n);
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> vp[i].first;
			vp[i].second = i;
			a[i] = vp[i].first;
		}
		sort(vp.begin(), vp.end());
		vector<int> ans(n);
		bool ok = 1;
		for (int i = 1, j = n; i < vp.size(); j--, i++) {
			if (j == a[0])j--;
			int ind = n - vp[i].second;
			ind %= n;
			// if (ind > n)cout << "nafi";
			ans[ind] = j;
		}
		for (int i = 0; i < n; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		map<int, int> m;
		for (int i = 0; i < n; i++) {
			m[ans[i]]++;
			if (m[ans[i]] > 1)ok = 0;
		}
		if (ok) {
			deque<int> d;
			for (int i = 0; i < n; i++) {
				if (d.empty())d.push_back(ans[i]);
				else if (d.back() < ans[i])d.push_back(ans[i]);
			}
			// for (int i = 0; i < d.size(); i++)cout << d[i] << ' ';
			// cout << '\n';
			if (d.size() != a[0])ok = 0;
			for (int i = n - 1, j = 1; i >= 1 && ok; i--, j++) {
				if (d.front() > ans[i])d.push_front(ans[i]);
				else {
					// while(d.back() >= ans[i])d.pop_back();
					while (!d.empty() && d.front() <= ans[i])d.pop_front();
					d.push_front(ans[i]);
				}
				if (d.size() != a[j]) {
					ok = 0;
					break;
				}
			}
			if (ok)cout << "yes\n";
			else cout << "no\n";
		} else cout << "no\n";
	}
	return 0;
}