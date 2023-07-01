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
		int x;
		for (int i = 0; i < n; i++) {
			cin >> x;
		}
		cout << x << '\n';
	}
	return 0;
}