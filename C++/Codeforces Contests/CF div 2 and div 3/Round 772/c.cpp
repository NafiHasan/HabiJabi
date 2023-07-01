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
		vector<long long> a(n);
		bool ys = 1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i && a[i] < a[i - 1])ys = 0;
		}
		if (a[n - 2] > a[n - 1]) {
			cout << "-1\n";
			continue;
		} else {
			if (a[n - 2] - a[n - 1] > a[n - 2]) {
				if (ys) {
					cout << "0\n";
					continue;
				} else {
					cout << "-1\n";
					continue;
				}
			}
			cout << n - 2 << '\n';
			for (int i = 0; i < n - 2; i++) {
				cout << i + 1 << ' ' << n - 1 << ' ' << n  << '\n';
			}
		}
	}
	return 0;
}