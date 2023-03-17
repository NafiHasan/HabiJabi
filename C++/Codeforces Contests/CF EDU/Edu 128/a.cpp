#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int l1, l2, r1, r2;
		cin >> l1 >> l2 >> r1 >> r2;
		if (r1 >= l1 && r1 <= l2)cout << r1 << '\n';
		else if (l1 >= r1 && l1 <= r2)cout << l1 << '\n';
		else cout << l1 + r1 << '\n';
	}
	return 0;
}