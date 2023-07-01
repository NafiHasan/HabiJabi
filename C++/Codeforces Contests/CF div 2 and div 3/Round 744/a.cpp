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
		int a = 0, b = 0, c = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'A')a++;
			else if (s[i] == 'B') b++;
			else c++;
		}
		if (a + c == b)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}