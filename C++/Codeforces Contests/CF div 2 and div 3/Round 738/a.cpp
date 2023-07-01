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
		int a[n];
		for (int i = 0; i < n; i++)cin >> a[i];
		int ans = a[0];
		for (int i = 1; i < n; i++)ans &= a[i];
		cout << ans << "\n";
	}
	return 0;
}