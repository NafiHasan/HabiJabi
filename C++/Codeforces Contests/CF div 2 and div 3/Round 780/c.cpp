#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		int n = s.size();
		// map<char, int> m;
		// for (int i = 0; i < n; i++)m[s[i]]++;
		int cnt = 0;
		vector<string> vs;
		string tmp = "";
		for (int i = 0; i < n; i++) {
			if (s[i] == '.')continue;
			if (i < n - 1 && s[i] == s[i + 1]) {
				s[i] = '.', s[i + 1] = '.';
				if (tmp != "")vs.push_back(tmp);
				tmp = "";
			} else {
				tmp += s[i];
			}
		}
		if (tmp != "")vs.push_back(tmp);
		for (int i = 0; i < vs.size(); i++) {
			sort(vs[i].begin(), vs[i].end());
			bool fo = 0;
			for (int j = 0; j < vs[i].size(); j++) {
				if (j && vs[i][j] == vs[i][j - 1]) {
					cnt += vs[i].size() - 2;
					fo = 1;
					break;
				}
			}
			if (!fo) cnt += vs[i].size();
		}
		cout << cnt << '\n';
	}
	return 0;
}