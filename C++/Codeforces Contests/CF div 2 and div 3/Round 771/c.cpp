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
		set<int> s;
		for (int i = 0; i < n; i++) cin >> a[i];
		int ans = 0;
		for (int i = 0; i < n; i++) {
			s.insert(a[i]);
			auto it = s.end();
			it--;
			if (s.size() == *it)ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}