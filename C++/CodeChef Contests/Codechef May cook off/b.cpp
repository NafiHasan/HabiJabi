#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int x, y;
		cin >> x >> y;
		if (100 * x >= 10 * y) {
			cout << "Cloth\n";
		} else cout << "Disposable\n";
	}
	return 0;
}