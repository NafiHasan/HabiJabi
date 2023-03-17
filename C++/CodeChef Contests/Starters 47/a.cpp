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
		vector<int> a(n);
		int ind1 = 0, ind2;
		for (int i = 0 ; i < n; i++) {
			cin >> a[i];
			if (a[i] == 1)ind1 = i;
			if (a[i] == n)ind2 = i;
		}
		int ans = ind1 + (n - ind2 - 1);
		if (ind2 < ind1)ans--;
		cout << ans << '\n';
	}
	return 0;
}