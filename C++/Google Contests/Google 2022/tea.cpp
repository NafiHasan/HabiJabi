#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		int n, m , p;
		cin >> n >> m >> p;
		vector<string>order(n), forbid(m);
		for (int i = 0; i < n; i++)cin >> order[i];
		for (int i = 0; i < m; i++)cin >> forbid[i];
		vector<int> cnt1(p);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < p; j++) {
				if (order[i][j] == '1')cnt1[j]++;
			}
		}
		vector<pair<int, int>> vp()
	}
	return 0;
}