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
		vector<vector<int>> a(80, vector<int> (80));
		vector<int> t1(80), t2(80);
		int cnt = 0, pre = 1;
		for (int i = 1; i < 80 - 1; i++) {
			if (cnt == 2) {
				cnt = 0;
				pre = 1 - pre;
			}
			t1[i] = 1 - pre;
			cnt++;
		}
		t1[0] = 1, t1[79] = 0;
		cnt = 0, pre = 0;
		for (int i = 1; i < 80 - 1; i++) {
			if (cnt == 2) {
				cnt = 0;
				pre = 1 - pre;
			}
			t2[i] = 1 - pre;
			cnt++;
		}
		t2[0] = 0, t2[79] = 1;
		// for (int i = 0; i < 80; i++)cout << t2[i] << ' ';
		cnt = 0, pre = 1;
		for (int i = 1; i < 80 - 1; i++) {
			if (cnt == 2) {
				cnt = 0;
				pre = 1 - pre;
			}
			if (pre == 0) {
				a[i] = t1;
			} else a[i] = t2;
			cnt++;
		}
		a[0] = t1;
		a[79] = t2;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)cout << a[i][j] << ' ';
			cout << '\n';
		}
	}
	return 0;
}