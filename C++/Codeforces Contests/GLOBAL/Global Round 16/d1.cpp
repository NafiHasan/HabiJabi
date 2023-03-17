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
		vector<int>a(m * n), sorted(m * n);
		for (int i = 0 ; i < m * n; i++)cin >> a[i];
		sorted = a;
		sort (sorted.begin(), sorted.end());
		int sc = m * n;
		vector<int>done(sc, 0);
		long long ans = 0;
		for (int i = 0; i < m * n ; i++) {
			int need = a[i], ind = 0;
			int lo = 0, hi = n * m - 1, mid;
			int run = 0;
			int tmp = -1;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (mid == 3) cout << 'g';
				if (sorted[mid] > need)hi = mid - 1;
				else if (sorted[mid] < need) lo = mid + 1;
				else if (sorted[mid] == need && done[mid] == 1) {
					hi = mid - 1;
				} else if (sorted[mid] == need && done[mid] == 0) {
					ind = mid;
					lo = mid + 1;
				}
			}
			// if (tmp != -1)ind = tmp;
			// cout << i << ' ' << ind << '\n';
			int ro = (ind + 1) / m;
			if ((ind + 1) % m == 0)ro--;
			int st = ro * m;
			if (st > 0 && sorted[st - 1] == need && done[st - 1] == 0) {
				ind = st - 1;
				st -= m;
			}
			// cout << i << ' ' << st << ' ' << ind  << '\n';
			for (int j = st; j < ind; j++) {
				if (i == 8)cout << done[3] << ' ' ;
				if (sorted[j] != need && done[j] >= 1) {
					ans++;
					cout << i << ' ' << j << '\n';
				}
			}
			done[ind] = 1;
			// cout << ind << 'a';
		}
		cout << ans << '\n';
	}
	return 0;
}