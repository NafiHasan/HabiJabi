#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n, m , k;
	cin >> n >> m >> k;
	vector<int> a(n);
	int cnt = 0, found = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > m)cnt++;
		if (a[i] == m)found = 1;
	}
	if (cnt > 0 && cnt <= k) {
		cout << "YES\n";
	} else if (found == 1 && cnt <= k) {
		cout << "YES\n";

	} else if (found + cnt == 0 && k > 0)cout << "YES\n";
	else cout << "NO\n";

	return 0;
}