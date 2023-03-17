#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	long long x, y;
	cin >> x >> y;
	int ans = 0;
	while (x <= y) {
		x *= 2;
		ans++;
	}
	cout << ans << '\n';
	return 0;
}