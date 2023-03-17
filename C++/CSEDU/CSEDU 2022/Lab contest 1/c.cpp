#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int cs = 1;
	while (1) {
		int n;
		cin >> n;
		if (n == 0)break;
		map<int, int> m;
		int mx = 0;
		for (int i = 0; i < n; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			mx = max(mx, b);
			m[a]++;
			while (a < 10000) {
				a += (c - b);
				m[a]++;
			}
		}
		int ans = -1;
		for (int i = mx; i < 10000; i++) {
			if (m[i] == n) {
				ans = i;
				break;
			}
		}
		cout << "Case #" << cs++ << ":\n";
		if (ans == -1) {
			cout << "Unknown bugs detected.\n";
		} else {
			cout << "The actual year is " << ans << ".\n";
		}
		cout << "\n";
	}
	return 0;
}