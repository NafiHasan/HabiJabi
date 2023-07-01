#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int r, c;
		cin >> r >> c;
		int mat[r + 2][c + 2];
		memset(mat, 0, sizeof(mat));
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (i == 1 && j % 2)mat[i][j] = 1;
				else if (i == r && mat[i - 1][j] == 0 && mat[i][j - 1] == 0 && mat[i - 1][j + 1] == 0 && mat[i - 1][j - 1] == 0 )mat[i][j] = 1;
				else if (i > 1 && i < r && i % 2 && (j == 1 || j == c))mat[i][j] = 1;
			}
		}
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++)cout << mat[i][j];
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}