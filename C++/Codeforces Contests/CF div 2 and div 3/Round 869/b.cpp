#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << "1\n";
			continue;
		}
		if (n % 2 == 1) {
			cout << "-1\n";
			continue;
		}
		if ((n * (n + 1) / 2) % n == 0) {
			cout << "-1\n";
			continue;
		}
		for (int i = 1; i <= n; i += 2) {
			cout << i + 1 << ' ' << i << ' ';
		}
		cout << '\n';
	}
	return 0;
}