#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n * 2);
		for (int i = 0; i < 2 * n; i++)cin >> a[i];
		sort(a.begin(), a.end());
		bool ans = 1;
		for (int i = 0, j = n ; i < n; i++, j++) {
			if (a[j] - a[i] < x) {
				ans = 0;
				break;
			}
			// if (mp[i] == 1)continue;
			// mp[i] = 1;
			// bool f = 0;
			// for (int j = i + 1; j < 2 * n; j++) {
			// 	if (mp[j] == 1)continue;
			// 	if (a[j] - a[i] >= x) {
			// 		f = 1;
			// 		mp[j] = 1;
			// 		break;
			// 	}
			// }
			// if (!f) {
			// 	ans = 0;
			// 	break;
			// }

		}
		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}