#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(m, 0);
		for (int i = 0; i < m; i++) {
			cin >> a[i];
		}
		int ans = INT_MAX;
		int lo = 1, hi = INT_MAX - 1, mid;
		while (lo <= hi) {
			mid = (lo  + hi) / 2;
			bool done = 1;
			vector<int> av(n + 1, 0), cop(m);
			cop = a;
			for (int i = 0; i < m ; i++) {
				if (av[a[i]] < mid) {
					av[a[i]]++;
					cop[i] = -1;
				}
			}
			vector<int> tmp;
			for (int i = 1; i <= n; i++) {
				if (av[i] < mid)tmp.push_back(i);
			}
			for (int i = 0; i < cop.size(); i++) {
				if (cop[i] == -1)continue;
				if (tmp.size() == 0) {
					done = 0;
					break;
				}
				int last = tmp.back();
				if (av[last] < mid && cop[i] == last)av[last]++;
				else if (av[last] < mid - 1 && cop[i] != last) av[last] += 2;
				else {
					tmp.pop_back();
					i--;
					continue;
				}
			}
			if (done == 1) {
				ans = min(ans, mid);
				hi = mid - 1;
			} else lo = mid + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}