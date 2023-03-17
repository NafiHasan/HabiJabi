#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n, m, k;
void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	int a[k];
	int check[k + 1 + 1];

	for (int i = 0; i < k; i++) {
		cin >> a[i];
		check[i + 1] = 0;
	}

	int p = 0;

	for (int i = k - 1; i >= 0; i--) {
		check[a[i]] = 1;

		if (k - i - 1 - p > (m * n) - 3) {
			cout << "TIDAK" << endl;
			return;
		}

		while (check[p + 1] == 1 && p < k) {
			p++;
		}

		// cout << a[i] << endl;
		// cout << p << endl;
	}

	cout << "YA" << endl;
}


int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}
	return 0;
}