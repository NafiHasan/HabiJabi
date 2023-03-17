#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case " << cs << ": ";
		int n;
		cin >> n;
		n *= 2;
		vector<int> a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		int ans = 0;
		for (int i = 1; i < n; i += 2) {
			ans ^= a[i] - a[i - 1] - 1;
		}
		if (ans == 0)cout << "Bob\n";
		else cout << "Alice\n";
	}
	return 0;
}