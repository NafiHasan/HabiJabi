#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case #" << cs << ": ";
		vector<vector<int>> v(3, vector<int> (4, 0));
		vector<int> ans(4, 10000000);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> v[i][j];
				ans[j] = min(ans[j], v[i][j]);
			}
		}
		int sum = 0;
		for (int i = 0; i < 4; i++)sum += ans[i];
		if (sum < 1000000) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		int req = 1000000;
		for (int i = 0; i < 4; i++) {
			if (ans[i] > req) {
				ans[i] = req;
			}
			req -= ans[i];
		}
		for (int i = 0; i < 4; i++)cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}