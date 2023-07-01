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
		vector<int> a(n + 1, 0);
		for (int i = 1; i <= n; i++)cin >> a[i];
		bool ans = 1;
		for (int i = 2; i <= n ; i++) {
			if (a[i - 1] != 0 && a[i] % a[i - 1] == 0) {
				a[i] = a[i - 1];
			} else ans = 0;
		}

		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}