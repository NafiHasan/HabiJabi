#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n, q;
	cin >> n >> q;
	map<string, long long> m;
	for (int i = 0; i < n; i++) {
		string s;
		long long val;
		cin >> s >> val;
		m[s] += val;
	}
	long long ans = 0;
	while (q--) {
		string s;
		cin >> s;
		ans += m[s];
	}
	cout << ans << '\n';
	return 0;
}