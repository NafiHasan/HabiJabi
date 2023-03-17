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
		map<char, int> m;
		bool ans = 1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'r' || s[i] == 'g' || s[i] == 'b')m[s[i]]++;
			else if (s[i] == 'R' && m['r'] == 0)ans = 0;
			else if (s[i] == 'G' && m['g'] == 0)ans = 0;
			else if (s[i] == 'B' && m['b'] == 0)ans = 0;
		}
		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}