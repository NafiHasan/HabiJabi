#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int q;
	cin >> q;
	map<int, int> mp;
	set<int> st;
	set<int, greater<int>> st2;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x;
			cin >> x;
			st.insert(x);
			st2.insert(x);
			mp[x]++;
		} else if (t == 2) {
			int x, c;
			cin >> x >> c;
			mp[x] = max(0, mp[x] - c);
			if (mp[x] == 0 && st.find(x) != st.end()) {
				st.erase(st.find(x));
				st2.erase(st2.find(x));
			}
		} else {
			int mn = *st.begin();
			int mx = *st2.begin();
			cout << mx - mn << '\n';
		}
	}
	return 0;
}