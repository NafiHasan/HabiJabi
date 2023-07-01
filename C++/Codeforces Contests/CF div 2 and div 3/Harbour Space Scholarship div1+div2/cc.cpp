#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int ans = 0;

void check(string s) {
	int a = 0, b = 0;
	for (int i = 0; i < 10; i++) {
		if (s[i] == '1' && i % 2) b++;
		else if (s[i] == '1' && i % 2 == 0)a++;
		int rem = 9 - i;
		if (a < b) {
			int gota = rem / 2;
			if (a + gota < b)ans = min(ans, i + 1);
		} else if (a > b) {
			int gotb = rem / 2;
			if (rem % 2)gotb++;
			if (b + gotb < a)ans = min(ans, i + 1);
		}
	}
	return ;
}

void make(string s, int pos) {
	if (pos == 10) {
		check(s);
		return;
	}
	if (s[pos] == '1' || s[pos] == '0')make(s, pos + 1);
	else {
		s[pos] = '1';
		make(s, pos + 1);
		s[pos] = '0';
		make(s, pos + 1);
	}
	return ;
}

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		string s ;
		cin >> s;
		ans = 10;
		make(s, 0);
		cout << ans << "\n";
	}
	return 0;
}