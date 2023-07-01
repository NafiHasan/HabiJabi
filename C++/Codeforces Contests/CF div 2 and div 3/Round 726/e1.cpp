#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int ind = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] > s[0]) {
			ind = i;
			break;
		}
	}
	int now = n - 1;
	while (ind > 0 && now >= ind) {
		s.pop_back();
		now--;
	}
	int sz = (int)s.size();
	while (sz < k) {
		s += s;
		sz += sz;
	}
	sz = (int)s.size();
	while (sz > k) {
		s.pop_back();
		sz--;
	}
	cout << s << "\n";
	return 0;
}