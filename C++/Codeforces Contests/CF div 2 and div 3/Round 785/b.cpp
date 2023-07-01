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
		map<char, int> m;
		string rep = "";
		for (int i = 0; i < n; i++) {
			m[s[i]]++;
			if (m[s[i]] == 1) {
				rep += s[i];
			}
		}
		string ans = "";
		while (ans.size() < n)ans += rep;
		while (ans.size() > n)ans.pop_back();
		if (ans == s) {
			cout << "YES\n";
		} else cout << "NO\n";
	}
	return 0;
}