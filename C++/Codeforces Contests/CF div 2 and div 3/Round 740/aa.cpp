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
		vector<int>a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		int ans = 0;
		while (1) {
			bool ys  = 1;
			for (int i = 0; i < n; i++) {
				if (a[i] != i + 1)ys = 0;
			}
			if (ys)break;
			for (int i = ans % 2; i < n - 1; i += 2) {
				if (a[i] > a[i + 1])swap(a[i], a[i + 1]);
			}
			ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}