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
		if (n == 3) {
			cout << "-1\n";
			continue;
		}
		vector<int> a(n);
		for (int i = 2, j = 1; i < n; i++, j++)a[i] = j;
		a[0] = n, a[1] = n - 1;
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}