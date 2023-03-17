#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// class sparseTable {
// private:
// 	int N;
// 	int st[100005][25];
// 	in lg[100005], a[100005];

// 	// void comp() {
// 	// 	for (int i = 0; i < N; i++) {
// 	// 		st[i][0] = a[i];
// 	// 	}

// 	// 	for (int j = 1; j < 20; j++) {
// 	// 		for (int i = 0; i + (1 << j) <= N; i++) {
// 	// 			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1 ]);
// 	// 		}
// 	// 	}

// 	// 	lg[1] = 0;
// 	// 	for (int i = 2; i <= N; i++) {
// 	// 		lg[i] = lg[i / 2] + 1;
// 	// 	}
// 	// }

// public:
// 	sparseTable(vector<int> v, int n) {
// 		cout << "F";
// 		N = n;
// 		// for (int i = 0; i < v.size(); i++) {
// 		// 	a[i] = v[i];
// 		// }
// 		// comp();
// 	}

// 	// 1-based indexing
// 	// int query(int l, int r) {
// 	// 	l--, r--;
// 	// 	int j = lg[r - l + 1];
// 	// 	return min(st[l][j], st[r - (1 << j) + 1][j]);
// 	// }
// };


// void sparseTable(vector<int> v) {
// 	int n = v.size();
// 	int st[n + 5][25], lg[n + 5];

// 	for (int i = 0; i < n; i++) st[i][0] = v[i];

// 	for (int j = 1; j < 20; j++) {
// 		for (int i = 0; i + (1 << j) <= n; i++) {
// 			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1 ]);
// 		}
// 	}

// 	lg[1] = 0;
// 	for (int i = 2; i <= n; i++) {
// 		lg[i] = lg[i / 2] + 1;
// 	}
// }

int main() {
	FastIO;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)cin >> a[i];
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		int j = lg[r - l + 1];
		cout << min(st[l][j], st[r - (1 << j) + 1][j]) << '\n';
	}

	return 0;
}