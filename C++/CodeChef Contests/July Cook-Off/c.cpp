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
		vector<int> a(n, 0);
		int f = 1, l = n;
		for (int i = 0; i < n; i++)a[i] = i + 1;
		for (int i = 0; i < n - 3; i++) {
			if ((a[i] ^ a[i + 1]) == a[i + 2])swap(a[i + 2], a[i + 3]);
		}
		if (n == 6) {
			a[0] = 1;
			a[1] = 3;
			a[2] = 4;
			a[3] = 5;
			a[4] = 6;
			a[5] = 2;
		}
		if (n == 3) {
			cout << "-1\n";
		} else {
			for (int i = 0; i < n ; i++) {
				cout << a[i] << ' ';
			}
			cout << "\n";
		}
	}
	return 0;
}