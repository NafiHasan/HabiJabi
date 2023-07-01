#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		string s, t;
		cin >> s >> t;
		int n = s.size(), m = t.size();
		if (m > n) {
			cout << "NO\n";
			continue;
		}
		vector<int>odd[27], even[27], have;
		for (int i = 0; i < n; i++) {
			if (s[i] == t[0] && i + m <= n)have.push_back(i);
			int pos = s[i] - 'a';
			if (i % 2) odd[pos].push_back(i);
			else even[pos].push_back(i);
		}
		int par = 0, ans = 0;
		for (int j = 0; j < have.size(); j++) {
			par = have[j] % 2;
			int last = have[j];
			bool found = 1;
			for (int i = 1; i < m; i++) {
				int p = -1;
				if (par == 0) {
					p = lower_bound(odd[t[i] - 'a'].begin(), odd[t[i] - 'a'].end(), last + 1) - odd[t[i] - 'a'].begin();
					if (p == (int)odd[t[i] - 'a'].size())p = -1;
				} else {
					p = lower_bound(even[t[i] - 'a'].begin(), even[t[i] - 'a'].end(), last + 1) - even[t[i] - 'a'].begin();
					if (p == (int)even[t[i] - 'a'].size())p = -1;
				}
				par = 1 - par;
				last = p;
				if (p == -1) {
					found = 0;
					break;
				}
			}
			if (found && par != n % 2) {
				ans = 1;
				break;
			}
		}
		if (ans == 1)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}