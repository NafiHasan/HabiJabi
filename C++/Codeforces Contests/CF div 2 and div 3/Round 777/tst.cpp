#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<string> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<int> cnt(n, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '1')cnt[i]++;
			}
		}
		bool ans = 1;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '1' && a[i - 1][j] == '1' && cnt[i - 1] != cnt[i])ans = 0;
			}
		}
		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}