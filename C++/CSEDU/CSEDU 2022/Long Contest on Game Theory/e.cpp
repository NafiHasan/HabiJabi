#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case " << cs << ": ";
		int m, n;
		cin >> m >> n;
		long long ans = 0;
		for (int i = 0; i < m; i++) {
			long long sum = 0;
			for (int j = 0; j < n; j++) {
				long long x;
				cin >> x;
				sum += x;
			}
			ans ^= sum;
		}
		if (ans == 0)cout << "Bob\n";
		else cout << "Alice\n";
	}
	return 0;
}