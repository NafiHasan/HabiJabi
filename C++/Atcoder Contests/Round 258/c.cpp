#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	int rot = 0;
	while (q--) {
		int t, x;
		cin >> t >> x;
		if (t == 1) {
			rot += x;
			rot %= n;
		} else {
			int ind;
			if (x <= rot) {
				ind = n - rot + x - 1;
				cout << s[ind] << '\n';
			} else {
				cout << s[x - rot - 1] << '\n';
			}
		}
	}
	return 0;
}