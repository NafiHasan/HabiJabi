#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)cin >> a[i];

		sort(a.begin(), a.end());
		bool ans = 1;
		for (int i = 1; i < n - 1; i++) {
			if ((a[i] - a[i - 1]) == (2 * (a[i + 1] - a[i])))continue;
			if ((a[i + 1] - a[i]) == (2 * (a[i] - a[i - 1])))continue;
			ans = 0;
		}
		if (ans)cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}