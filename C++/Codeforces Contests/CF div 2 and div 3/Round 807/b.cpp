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
		deque<int> a(n);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> a[i];
		}
		// while (!a.empty() && a[0] == 0) {
		// 	a.pop_front();
		// }
		int start = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] == 0)continue;
			else {
				start = i;
				break;
			}
		}
		long long ans = 0;
		if (start == -1) {
			cout << "0\n";
			continue;
		}
		for (int i = start; i < n - 1; i++) {
			if (a[i] == 0)ans++;
			else ans += a[i];
		}
		cout << ans << '\n';
	}
	return 0;
}