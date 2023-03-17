#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	w(t) {
		string s;
		cin >> s;
		deque<char>d, tmp;
		ll ans = 0;
		int ex ;
		for (int i = 0; i < s.size(); i++) {
			if (i == 0) {
				d.push_back(s[i]);
				if (s[i] == '0')ex = 1;
				else if (s[i] == '1')ex = 0;
				else ex = 2;
				ans += (ll)d.size();
			} else {
				if (ex == 1 && s[i] == '1') {
					d.push_back(s[i]);
					ex = 0;
				} else if (ex == 0 && s[i] == '0') {
					d.push_back(s[i]);
					ex = 1;
				} else if (s[i] == '?') {
					d.push_back(s[i]);
					ex = 1 - ex;
				} else {
					d = tmp;
					cout << (int) tmp.size() << en;
					d.push_back(s[i]);
					if (s[i] == '1')ex = 0;
					else if (s[i] == '0')ex = 1;
				}
				ans += (ll)d.size();
			}
			if (s[i] == '?') tmp.push_back('?');
			else tmp.clear();
		}
		cout << ans << en;
	}
	return 0;
}