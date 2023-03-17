#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int pre = 1, cnt = 0;
		for (int i = n - 1; i >= 0 ; i--) {
			if (pre == 1 && s[i] == '0') {
				pre = 0;
			}
			if (pre == 0 && s[i] == '1') {
				cnt++;
				pre = 1;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}