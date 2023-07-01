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
		vector<string>v(n);
		for (int i = 0; i < n; i++)cin >> v[i];
		priority_queue<int>dif[28];
		for (int let = 0; let < 26; let++) {
			for (int i = 0; i < n; i++) {
				int tot = 0,  cur = 0;
				for (int j = 0; j < v[i].size(); j++) {
					if (v[i][j] == (char)(let + 'a'))cur++;
					else tot++;
				}
				dif[let].push(cur - tot);
				// cout << (char)(let + 'a') << " " << cur - tot << "\n";
			}
		}
		int adv = 0, ans = 0;
		for (int let = 0; let < 26; let++) {
			int best = 0;
			adv = 0;
			while (!dif[let].empty()) {
				int top = dif[let].top();
				dif[let].pop();
				// if (let == 0)cout << top << "\n";
				if (top > 0) {
					best++;
					adv += top;
				} else if (adv + top > 0) {
					best++;
					adv = adv + top;
				}
			}
			// cout << (char) (let + 'a') << " " << best << "\n";
			ans = max(ans, best);
		}
		cout << ans << "\n";
	}
	return 0;
}