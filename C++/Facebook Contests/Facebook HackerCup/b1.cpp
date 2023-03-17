#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case #" << cs << ": ";
		int r, c;
		cin >> r >> c;
		vector<string> grid(r);
		for (int i = 0; i < r; i++)cin >> grid[i];
		bool has = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (grid[i][j] == '^') {
					has = 1;
					break;
				}
			}
		}
		if (r == 1 || c == 1) {
			if (has) {
				cout << "Impossible\n";
			} else {
				cout << "Possible\n";
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						cout << "." ;
					}
					cout << "\n";
				}
			}
		} else {
			cout << "Possible\n";
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					cout << "^";
				}
				cout << "\n";
			}
		}
	}
	return 0;
}