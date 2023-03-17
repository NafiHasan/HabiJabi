#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		cin >> m;
		vector<int> b(m);
		for (int i = 0; i < m; i++)cin >> b[i];
		int mx1 = *max_element(a.begin(), a.end());
		int mx2 = *max_element(b.begin(), b.end());
		if (mx1 == mx2) {
			cout << "Alice\nBob\n";
		} else if (mx1 < mx2) {
			cout << "Bob\nBob\n";
		} else cout << "Alice\nAlice\n";
	}
	return 0;
}