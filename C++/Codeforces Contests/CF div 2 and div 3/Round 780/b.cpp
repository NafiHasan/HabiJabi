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
		vector<int> a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		if (n == 1) {
			if (a[0] > 1) {
				cout << "NO\n";
				continue;
			} else {
				cout << "YES\n";
				continue;
			}
		}
		sort(a.begin(), a.end());
		if (a[n - 1] - a[n - 2] <= 1)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}