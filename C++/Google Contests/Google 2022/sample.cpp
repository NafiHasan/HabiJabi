#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	int cs = 1;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			sum += x;
		}
		cout << "Case #" << cs++ << ": " << (sum % m) << "\n";
	}
	return 0;
}