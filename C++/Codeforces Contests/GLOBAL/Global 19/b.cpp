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
		vector<int> a(n), fre(n + 1, 0);
		int cnt = 0;
		fre[0 ]  = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] == 0)cnt++;
			fre[i + 1] = cnt;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				ans += fre[j + 1] - fre[i] + j - i + 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}