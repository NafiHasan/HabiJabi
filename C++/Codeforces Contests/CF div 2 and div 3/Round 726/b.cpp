#include <bits/stdc++.h>

using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, x, y;
		cin >> n >> m >> x >> y;
		int dist1 = abs(1 - x) + abs(1 - y) + abs(n - x) + abs(m - y);
		int dist2 = abs(1 - x) + abs(m - y) + abs(n - x) + abs(1 - y);
		if (dist1 < dist2) cout << 1 << " " << m << " " << n << " " << 1 << "\n";
		else cout << "1 1 " << n << " " << m << "\n";
	}
	return 0;
}