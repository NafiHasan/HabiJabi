#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, l , r;
		cin >> n >> l >> r;
		vector<int> a(n, -1);
		bool ans = 1;
		for (int i = 1; i <= n; i++) {
			if (l % i == 0) {
				a[i - 1] = l;
			} else {
				if ((l + i - (l % i)) <= r)a[i - 1] = l + i - (l % i);
				else {
					ans = 0;
					break;
				}
			}
		}
		if (ans) {
			cout << "YES\n";
			for (int i = 0; i < n; i++)cout << a[i] << ' ' ;
			cout << '\n';
		} else cout << "NO\n";
	}
	return 0;
}