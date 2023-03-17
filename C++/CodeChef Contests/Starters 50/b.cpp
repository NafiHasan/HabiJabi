#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, x;
		cin >> n >> x;
		if (x < n) {
			cout << "-1\n";
			continue;
		}
		int done = x - n + 1;
		cout << done << ' ';
		for (int i = 1; i <= n; i++) {
			if (i != done)cout << i << ' ';
		}
		cout << '\n';
	}
	return 0;
}