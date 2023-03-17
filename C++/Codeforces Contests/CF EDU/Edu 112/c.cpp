#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>>v(2, vector<int>(n));
		int sum = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> v[i][j];
				if (i < 1 && j > 0)sum += v[i][j];
			}
		}
		int ans = sum, down = 0;
		for (int i = 1; i < n; i++) {
			sum -= v[0][i];
			down += v[1][i - 1];
			ans = min(ans, max(sum, down));
		}
		cout << ans << "\n";
	}
	return 0;
}