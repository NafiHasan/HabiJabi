#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n, q;
	cin >> n >> q;
	map<int, int> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m[a[i]]++;
	}
	while (q--) {
		int x;
		cin >> x;
		cout << m[x] << '\n';
	}
	return 0;
}