#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++)a[i] = i;
		if (k < n - 1)swap(a[0], a[k]);
		else if (k == n - 1 && n == 4) {
			cout << "-1\n";
			continue;
		} else {
			swap(a[0], a[k - 1]);
			swap(a[3], a[k - 1]);
		}
		for (int i = 0; i < n / 2; i++) {
			cout << a[i] << ' ' << a[n - i - 1] << '\n';
		}
	}
	return 0;
}