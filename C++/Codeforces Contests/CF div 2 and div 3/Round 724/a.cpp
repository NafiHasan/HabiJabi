#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	w(t) {
		int n, m;
		cin >> n >> m;
		string s, now;
		cin >> s;
		for (int i = 1; i <= min(n, m); i++) {
			now = s;
			for (int j = 0; j < s.size(); j++) {
				if (j == 0 && s[j + 1] == '1')now[j] = '1';
				else if (j == (int)s.size() - 1 && s[j - 1] == '1')now[j] = '1';
				else if (j > 0 && j < (int)s.size() - 1) {
					if (s[j - 1] == '1' && s[j + 1] == '0')now[j] = '1';
					else if (s[j - 1] == '0' && s[j + 1] == '1')now[j] = '1';
				}
			}
			s = now;
		}
		cout << s << en;
	}
	return 0;
}