#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


// topdown

const int N = 50, inf = 1e9 + 7;

int grid[N][N] , row, col;


int main() {
	FastIO;
	cin >> row >> col;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> grid[i][j];
		}
	}
	grid[1][1] = grid[1][1];
	for (int i = 2; i <= row; i++) {
		grid[i][1] += grid[i - 1][1];
	}
	for (int i = 2; i <= col; i++) {
		grid[1][i] += grid[1][i - 1];
	}
	for (int i = 2; i <= row; i++) {
		for (int j = 2; j <= row; j++) {
			grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
		}
	}
	cout << grid[row][col] << '\n';
	return 0;
}






// // with memo

// const int N = 50, inf = 1e9 + 7;

// int grid[N][N] , row, col, cost[N][N];

// int rec(int r, int c) {
// 	if (r < 1 || c < 1)return inf;
// 	if (r == 1 && c == 1)return cost[r][c] = grid[r][c];
// 	if (cost[r][c] != -1)return cost[r][c];

// 	return cost[r][c] = grid[r][c] + min(rec(r - 1, c), rec(r, c - 1));
// }

// int main() {
// 	FastIO;
// 	cin >> row >> col;
// 	for (int i = 1; i <= row; i++) {
// 		for (int j = 1; j <= col; j++) {
// 			cin >> grid[i][j];
// 			cost[i][j] = -1;
// 		}
// 	}
// 	rec(row, col);
// 	cout << cost[row][col] << '\n';
// 	return 0;
// }









// // without memo

// const int N = 50, inf = 1e9 + 7;

// int grid[N][N] , row, col, cost = 0;

// int rec(int r, int c) {
// 	if (r < 1 || c < 1)return inf;
// 	if (r == 1 && c == 1)return grid[r][c];
// 	return grid[r][c] + min(rec(r - 1, c), rec(r, c - 1));
// }

// int main() {
// 	FastIO;
// 	cin >> row >> col;
// 	for (int i = 1; i <= row; i++) {
// 		for (int j = 1; j <= col; j++) {
// 			cin >> grid[i][j];
// 		}
// 	}
// 	cost = rec(row, col);
// 	cout << cost << '\n';
// 	return 0;
// }


// test:
// 5 5
// 1 2 3 1 1
// 1 22 30 4 1
// 1 22 32 4 1
// 1 2 3 10 5
// 1 2 3 4 5
// ans : 19