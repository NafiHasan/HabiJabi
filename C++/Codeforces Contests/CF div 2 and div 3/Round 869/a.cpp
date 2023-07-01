#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		vector<string> mat(n);
		for (int i = 0; i < n; i++)cin >> mat[i];
		vector<int> ans(n, 1);
		for (int j = 0; j < k; j++) {
			for (int i = 1; i < n; i++) {
				if (mat[i][j] != mat[0][j])ans[i] = 0;
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)if (ans[i] == 1)cnt++;
		cout << cnt << '\n';
	}
	return 0;
}