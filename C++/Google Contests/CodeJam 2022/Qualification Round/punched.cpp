#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		int r, c;
		cin >> r >> c;
		vector<string> ans(r * 2 + 1);
		for (int i = 0; i < r * 2 + 1; i++) {
			string tmp = "";
			if (i % 2 == 0) {
				for (int j = 0; j < c * 2 + 1; j++) {
					if (j % 2)tmp += '-';
					else tmp += '+';
				}
				ans[i] = tmp;
			} else {
				for (int j = 0; j < c * 2 + 1; j++) {
					if (j % 2)tmp += '.';
					else tmp += '|';
				}
				ans[i] = tmp;
			}
		}
		ans[0][0] = ans[0][1] = ans[1][0] = ans[1][1] = '.';
		cout << "Case #" << cs << ":\n";
		for (int i = 0; i < r * 2 + 1; i++) {
			cout << ans[i] << '\n';
		}
	}
	return 0;
}