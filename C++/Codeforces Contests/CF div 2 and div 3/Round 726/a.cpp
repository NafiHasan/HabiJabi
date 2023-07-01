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
		int a[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		int sum = accumulate(a, a + n, 0);
		if (sum % n == 0 && sum / n == 1) {
			cout << 0 << "\n";
			continue;
		} else if (sum < 0) {
			cout << 1 << "\n";
			continue;
		}
		if (sum < n) {
			cout << 1 << "\n";
			continue;
		}
		cout << sum - n << "\n";
	}
	return 0;
}