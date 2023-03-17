#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	multiset<int> g;
	multiset<int, greater<int> > s;
	int ans = 0, last = 1;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < n; i++) {
		int rm = i - k;
		if (g.size() + s.size() == k) ans = max(ans, *s.begin());
		if (i == 0) s.insert(a[i]);
		else if (g.size() == s.size()) {
			if (g.size() + s.size() == k) {
				if (g.find(a[rm]) != g.end()) {
					g.erase(g.find(a[rm]));
				} else {
					s.erase(s.find(a[rm]));
					s.insert(*g.begin());
					g.erase(g.find(*g.begin()));
				}
			} else {

			}
		}
	}
	return 0;
}