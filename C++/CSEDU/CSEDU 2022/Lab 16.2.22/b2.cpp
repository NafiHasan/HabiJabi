#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n, q;
	cin >> n >> q;
	map<long long, long long> m;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		m[x]++;
	}
	while (q--) {
		char c;
		long long val;
		cin >> c >> val;
		if (c == 'D') {
			m[val]--;
			m[val] = max(0LL, m[val]);
		} else if (c == 'I')m[val]++;
		else {
			if (m[val] > 0)cout << "Yes\n";
			else cout << "No\n";
		}
	}

	return 0;
}