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
		vector<int> a, b, c;
		map<int, int>mp;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			mp[x]++;
			if (mp[x] <= 2 )c.push_back(x);
		}
		sort(c.begin(), c.end());
		for (int i = 0; i < c.size(); i++) {
			if (i % 2)b.push_back(c[i]);
			else a.push_back(c[i]);
		}
		deque<int> d;
		for (int i = a.size() - 1; i >= 0; i--)d.push_front(a[i]);
		for (int i = b.size() - 1; i >= 0; i--)d.push_back(b[i]);
		int mx = 0, pre = -1;
		for (int i = 0; i < d.size(); i++) {
			if (d[i] > pre) {
				pre = d[i];
				mx++;
			}
			// cout << d[i] << ' ' ;
		}
		// cout << mx << '\n';
		int cnt = 0;
		pre = -1;
		for (int i = d.size() - 1; i >= 0; i--) {
			if (d[i] > pre) {
				pre = d[i];
				cnt++;
			}
		}
		mx = min(mx, cnt);
		cout << mx << '\n';
	}
	return 0;
}