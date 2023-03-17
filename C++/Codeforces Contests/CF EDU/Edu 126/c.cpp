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
		vector<int> a(n);
		int mx = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mx = max(mx, a[i]);
		}
		deque<int> rem;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int tmp = mx - a[i];
			ans += (tmp / 3) * 2;
			tmp %= 3;
			if (tmp > 0)rem.push_back(tmp);
			cout << tmp << ' ';
		}
		cout << "\n" << ans << '\n';
		sort(rem.begin(), rem.end());
		deque<int> d;
		while (!rem.empty()) {
			d.push_back(rem.front());
			rem.pop_front();
			if (rem.empty())break;
			d.push_back(rem.back());
			rem.pop_back();
		}
		for (int i = 1; i < d.size();) {
			if (d[i] != d[i - 1]) {
				ans += 2;
				d.pop_front();
				d.pop_front();
			} else break;
		}
		if (!d.empty()) {
			if (d[0] == 1) {
				ans += 2 * (int)d.size() - 1;
			} else {
				int ss = d.size();
				ans += ss + 1 + (ss / 3);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}