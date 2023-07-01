#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> mn(n + 5, 0), mx(n + 5, 0), curmax(n + 5, 0), curmin(n + 5, 0);
		mx[1] = 1;
		curmax[1] = 1;
		int last = 1;
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			if (c == '+') {
				last++;

				int u, val;
				cin >> u >> val;

				curmax[last] = max(0, curmax[u] + val);
				curmin[last] = min(0, curmin[u] + val);

				mn[last] = min(mn[last], mn[u]);
				mn[last] = min(mn[last], curmin[last]);
				// mn[last] = min(mn[last], mn[u] + val);
				mx[last] = max(mx[last], mx[u]);
				mx[last] = max(mx[last], curmax[last]);
				// mx[last] = max(mx[last], mx[u] + val);
			} else {
				int u, v, val;
				cin >> u >> v >> val;
				if (val >= mn[v] && val <= mx[v]) {
					cout << "YES\n";
				} else {
					cout << "NO\n";
				}
			}
		}
	}
	return 0;
}