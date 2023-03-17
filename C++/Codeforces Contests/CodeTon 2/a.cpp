#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool ans = 0;
string a, b;

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		ans = 1;
		cin >> n >> m;
		cin >> a >> b;
		for (int i = m - 1, j = n - 1; i > 0; i--, j--) {
			if (a[j] != b[i]) {
				ans = 0;
				break;
			}
		}
		bool f = 0;
		for (int i = 0; i <= (n - m); i++) {
			if (a[i] == b[0]) {
				f = 1;
				break;
			}
		}
		if (!f)ans = 0;
		if (ans)cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}