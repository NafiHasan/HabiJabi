#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		map<char, int>m;
		bool ok = 0;
		for (int i = 0; i < n; i++) {
			if (m[s[i]] > 0 && i && s[i] != s[i - 1]) {
				ok = 1;
				break;
			}
			m[s[i]]++;
		}
		if (ok)cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}