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
		for (int i = 0; i < s.size(); i++) {
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
			for (int i = 1; i < t.size(); i++) {
				int p = -1;
				int hi, mid, lo = 0;
				if (par == 0)hi = odd[t[i] - 'a'].size() - 1;
				else hi = even[t[i] - 'a'].size() - 1;
				while (lo <= hi) {
					mid = (lo + hi) / 2;
					if (par == 0) {
						if (odd[t[i] - 'a'][mid] <= last)lo = mid + 1;
						else {
							p = odd[t[i] - 'a'][mid];
							hi = mid - 1;
						}
					} else {
						if (even[t[i] - 'a'][mid] <= last)lo = mid + 1;
						else {
							p = even[t[i] - 'a'][mid];
							hi = mid - 1;
						}
					}
				}
				last = p;
				par = 1 - par;
				if (p == -1) {
					found = 0;
					break;
				}
			}
			if (found && par != (int)s.size() % 2) {
				ans = 1;
				break;
			}
		}
		if (ans == 1)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}