#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int a, b;
		cin >> a >> b;
		if (a == 0) {
			cout << "1\n";
			continue;
		}
		int cnt = a + b * 2;
		cout << cnt + 1 << '\n';
	}
	return 0;
}