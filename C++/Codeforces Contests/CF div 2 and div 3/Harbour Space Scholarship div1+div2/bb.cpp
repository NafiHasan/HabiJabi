#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool check (string s, string t, int left, int cur, int pos) {
	if (cur < t.size() && pos >= s.size())return 0;
	if (s[pos] == t[cur] && cur < t.size() - 1) {
		if (left == 0) {
			if (pos + 1 < s.size())return (check(s, t, 1, cur + 1, pos - 1) | check(s, t, 0, cur + 1, pos + 1));
			else return check(s, t, 1, cur + 1, pos - 1);
		} else {
			return check(s, t, 1, cur + 1, pos - 1);
		}
	} else if (cur == t.size() - 1 && pos < s.size() && s[pos] == t[cur])return 1;
	else return 0;
}


int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		string s, t;
		cin >> s >> t;
		char st = t[0];
		vector<int>have;
		for (int i = 0; i < s.size(); i++)if (s[i] == st)have.push_back(i);
		bool found = 0;
		for (int j = 0; j < have.size(); j++) {
			if (check(s, t, 0, 0, have[j])) {
				found = 1;
				break;
			}
		}
		if (found == 0)cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}