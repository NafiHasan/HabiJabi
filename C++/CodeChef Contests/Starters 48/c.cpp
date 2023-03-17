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
		map<int, int> done;
		vector<int> a(n + 1), cnt(n + 1, 0);
		for (int i = 1; i <= n ; i++) {
			cin >> a[i];
			cnt[a[i]]++;
		}
		sort(a.begin(), a.end());
		int ans = n + 1, lo = 1, hi = n, mid;
		while ( lo <= hi) {
			mid = (lo + hi) / 2;
			vector<int> got(mid + 1, 0);
			bool can = 1;
			for (int i = 1, j = 1; i <= n; i++, j++) {
				if (j > mid)j -= mid;
				if (got[j] >= a[i]) {
					can = 0;
					break;
				}
				got[j]++;
			}
			if (can) {
				ans = min(ans, mid);
				hi = mid - 1;
			} else lo = mid + 1;
		}
		// for (int i = 2; i <= n; i++) {
		// 	// if(a[i] == i && done[i] == 0){
		// 	// 	done[i]++;
		// 	// 	cnt[i] -= ans;
		// 	// 	if(cnt[i] > 0){
		// 	// 		ans += cnt[i];
		// 	// 	}
		// 	// }
		// 	// else {
		// 	// 	done[i]++;
		// 	// 	cnt[i] -= ans;
		// 	// 	if(cnt[i] > 0)
		// 	// }
		// 	// if (cnt[i] < ans) {
		// 	// 	gap += ans - cnt[i];
		// 	// 	continue;
		// 	// }
		// 	// cnt[i] -= gap;
		// 	// cnt[i] -= ans;
		// 	// if (cnt[i] <= 0)continue;
		// 	// ans += cnt[i];
		// }
		cout << ans << '\n';
	}
	return 0;
}