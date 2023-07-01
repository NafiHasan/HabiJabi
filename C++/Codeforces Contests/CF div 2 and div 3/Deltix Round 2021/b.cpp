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
		deque<int>a(n), odd, even;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] % 2)odd.push_back(i);
			else even.push_back(i);
		}
		if (abs((int)odd.size() - (int)even.size()) > 1) {
			cout << "-1\n";
			continue;
		}
		vector<int>pos(n, 0);
		int ans = 0;
		if (odd.size() > even.size()) {

			for (int i = 0; i < n; i++) {
				if (i % 2 == 0) {
					pos[i] = odd.front();
					odd.pop_front();
				} else {
					pos[i] = even.front();
					even.pop_front();
				}
			}
			for (int i = 0 ; i < n; i++) {
				if (pos[i] > i)ans += pos[i] - i;
			}
		} else if (odd.size() < even.size()) {
			for (int i = 0; i < n; i++) {
				if (i % 2 == 1) {
					pos[i] = odd.front();
					odd.pop_front();
				} else {
					pos[i] = even.front();
					even.pop_front();
				}
			}
			for (int i = 0 ; i < n; i++) {
				if (pos[i] > i)ans += pos[i] - i;
			}
		} else {
			int o = 0, e = 0;
			for (int i = 0; i < n; i++) {
				if (i % 2 == 0) {
					pos[i] = odd[o++];
					// odd.pop_front();
				} else {
					pos[i] = even[e++];
					// even.pop_front();
				}
			}
			o = 0, e = 0;
			int ans1 = 0, ans2 = 0;
			for (int i = 0 ; i < n; i++) {
				if (pos[i] > i)ans1 += pos[i] - i;
			}
			for (int i = 0; i < n; i++) {
				if (i % 2 == 1) {
					pos[i] = odd.front();
					odd.pop_front();
				} else {
					pos[i] = even.front();
					even.pop_front();
				}
			}
			for (int i = 0 ; i < n; i++) {
				if (pos[i] > i)ans2 += pos[i] - i;
			}
			ans = min(ans1, ans2);
		}
		cout << ans << "\n";
	}
	return 0;
}