#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n, q;
	cin >> n >> q;
	multiset<long long> s;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		s.insert(x);
	}
	while (q--) {
		char c;
		long long val;
		cin >> c >> val;
		if (c == 'I')s.insert(val);
		else if (c == 'D')s.erase(val);
		else if (c == 'S') {
			if (s.upper_bound(val) != s.end())cout << (*s.upper_bound(val)) << '\n';
			else cout << "No such number\n";
		}
	}
	return 0;
}