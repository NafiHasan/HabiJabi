#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

map<string, int> mp;
int f(string s) {
	int cnt = 0;
	if (mp[s] != 0)return mp[s];
	// cout << s << ' ';
	if (s.size() == 1 && s[0] == '.')return 2;
	else if (s.size() == 0 && s[0] != '.')return 1;
	for (int i = 0; i < s.size(); i++)if (s[i] != '.')cnt++;
	string tmp = s;
	bool ch = 0;
	int ans = 0, ans1 = 0, ans2 = 0;
	for (int i = 0; i < s.size(); i++) {
		tmp = s;
		if (s[i] != '.')continue;
		if (i == 0) {
			if (s[i + 1] != 'X') {
				tmp[i] = 'X';
				ans = f(tmp);
				if (ans == 1)ans1++;
				else if (ans == 2)ans2++;
				ch = 1;
			}
			if (s[i + 1] != 'O') {
				tmp[i] = 'O';
				ans = f(tmp);
				if (ans == 1)ans1++;
				else if (ans == 2)ans2++;
				ch = 1;
			}
		} else if (i == s.size() - 1) {
			if (s[i - 1] != 'X') {
				tmp[i] = 'X';
				ans = f(tmp);
				if (ans == 1)ans1++;
				else if (ans == 2)ans2++;

				ch = 1;
			}
			if (s[i - 1] != 'O') {
				tmp[i] = 'O';
				ans = f(tmp);
				if (ans == 1)ans1++;
				else if (ans == 2)ans2++;
				ch = 1;
			}
		} else {
			if (s[i - 1] != 'X' && s[i + 1] != 'X') {
				tmp[i] = 'X';
				// ans = min(ans, f(tmp));
				ans = f(tmp);
				if (ans == 1)ans1++;
				else if (ans == 2)ans2++;
				ch = 1;
			}
			if (s[i - 1] != 'O' && s[i + 1] != 'O') {
				tmp[i] = 'O';
				// ans = min(ans, f(tmp));
				ans = f(tmp);
				if (ans == 1)ans1++;
				else if (ans == 2)ans2++;
				ch = 1;
			}
		}
	}
	// if (ans == 2)cout << "s" << s << '\n';
	if (ch == 0) {
		// if (cnt % 2 == 1) {
		// 	return mp[s] = 2;
		// } else
		return mp[s] = 1;
	}
	// if (ans1 > 0 && cnt % 2 == 0)ans = 1;
	// else if (ans1 == 0 && cnt % 2 == 1)ans = 1;
	// // else if (ans2 == 0)ans = 1;
	// else ans = 2;
	if (ans1 > 0)ans = 2;
	cout << s << ' ' << ans1 << ' ' << ans2 <<  ' ' << ans << '\n';
	return mp[s] = ans;
}


int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case " << cs << ": ";
		string s;
		cin >> s;
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != '.')cnt++;
		}
		int ans = f(s);
		if (ans == 2 && cnt % 2 == 0)cout << "Yes\n";
		else if (ans == 1 && cnt % 2 == 1)cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}