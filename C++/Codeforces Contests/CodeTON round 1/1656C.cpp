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
		bool same = 1;
		map<int, int> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			m[a[i]]++;
			if (a[i] != a[0])same = 0;
		}
		if (same || m[1] == 0) {
			cout << "Yes\n";
			continue;
		}
		bool ok = 1;
		for (int i = 0; i < n; i++) {
			if (m[a[i] - 1] > 0)ok = 0;
		}
		if (ok)cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}