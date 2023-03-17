#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >>  tc;
	while (tc--) {
		int n;
		string s;
		cin >> n >> s;
		int dr = 0, win = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1')dr++;
			else win++;
		}
		if (win > 0 && win < 3) {
			cout << "NO\n";
			continue;
		}
		char ans[n][n];
		for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)ans[i][j] = '0';
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				for (int j = 0; j < n; j++) {
					if (i == j)ans[i][i] = 'X';
					else {
						ans[i][j] = '=';
						ans[j][i] = '=';
					}
				}
				continue;
			}
			bool done = 0;
			for (int j = 0; j < n; j++) {
				if (ans[i][j] != '0')continue;
				if (s[j] == '1')continue;
				if (i == j)ans[i][j] = 'X';
				else {
					if (s[j] == '2' && done == 0) {
						ans[i][j] = '+';
						ans[j][i] = '-';
						done = 1;
					} else if (s[j] == '2' && done) {
						ans[i][j] = '-';
						ans[j][i] = '+';
					}
				}
			}
		}
		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)cout << ans[i][j];
			cout << '\n';
		}
	}
	return 0;
}

