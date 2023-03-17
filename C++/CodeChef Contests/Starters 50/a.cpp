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
		vector<int> a(n);
		a[0] = n, a[n - 1] = n - 1;
		int now = n - 2;
		for (int i = 1, j = n - 2, cnt = 0; i <= j; cnt++) {
			if (cnt % 2 == 0 ) {
				a[i++] = now--;
			} else a[j--] = now--;
		}
		for (int i = 0; i < n; i++)cout << a[i] << ' ';
		cout << '\n';
	}
	return 0;
}