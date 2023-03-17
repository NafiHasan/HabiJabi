#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int r, c;
	cin >> r >> c;
	vector<string> a(r);
	for (int i = 0 ; i < r; i++)cin >> a[i];
	int x1 = -1, x2 = 0, y1 = 0, y2;
	for (int i = 0 ; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] == 'o') {
				if (x1 == -1) {
					x1 = i, y1 = j;
				} else {
					x2 = i, y2 = j;
				}
			}
		}
	}
	cout << abs(x1 - x2) + abs(y1 - y2) << '\n';
	return 0;
}