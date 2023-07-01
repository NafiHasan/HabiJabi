#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case #" << cs << ": ";
		vector<int> mp(26);
		for (int i = 0; i < 26; i++)cin >> mp[i];
		map<string, int> got;
		bool ans = 1;
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			string s, res = "";
			cin >> s;
			for (int j = 0; j < (int)s.size(); j++) {
				res += mp[s[j] - 'A'];
			}
			if (got[res] >= 1)ans = 0;
			got[res]++;
		}
		if (ans)cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}