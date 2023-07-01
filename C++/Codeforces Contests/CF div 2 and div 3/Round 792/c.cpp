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
		vector<vector<int>> a(n, vector<int> (m, 0)), cop(n, vector<int> (m, 0));
		map<vector<int> , int>mp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				cop[i][j] = a[i][j];
			}
			sort(cop[i].begin(), cop[i].end());
		}
		// for (int i = 0; i < n; i++) {
		// 	for (int j = 0; j < m; j++)cout << cop[i][j] << ' ';
		// 	cout << '\n';
		// }
		for (int j = 0; j < m; j++) {
			vector<int> tmp(n);
			for (int i = 0; i < n; i++) {
				tmp[i] = a[i][j];
				// cout << tmp[i] << ' ';
			}
			// sort(tmp.begin(), tmp.end());
			mp[tmp]++;
		}
		// cout << mp[ {1, 3}] << '\n';
		int sp = 0, col1 = -1, col2 = -1;
		bool ans = 1;
		for (int j = 0; j < m; j++) {
			vector<int> tmp(n), tmp2(n);
			for (int i = 0; i < n ; i++) {
				tmp[i] = cop[i][j];
				tmp2[i] = a[i][j];
				// cout << tmp[i] << ' ';
				if (a[i][j] != cop[i][j]) {
					if (col1 == -1)col1 = j + 1;
					else if (col2 == -1 && j + 1 != col1)col2 = j + 1;
				}
				// cout << tmp[i] << 'c' ;
			}
			// cout << '\n';
			// vector<int> sorttmp = tmp;
			// sort(sorttmp.begin(), sorttmp.end());
			if (mp[tmp] == 0) {
				// for (int i = 0; i < n; i++)cout << tmp[i] << ' ';
				// cout << '\n';
				ans = 0;
				break;
			}
			if (tmp != tmp2)sp++;
			// if (ys)sp++;
		}
		if (col1 == -1 && col2 == -1) {
			col1 += 2;
			col2 += 2;
		}
		if (ans == 0 || sp > 2)cout << "-1\n";
		else cout  << col1 << ' ' << col2 << '\n';
	}
	return 0;
}