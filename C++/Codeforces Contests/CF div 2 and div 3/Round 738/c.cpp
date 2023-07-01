#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// vector<bool>vis(10005,0);
// vector<int>edge[10005];

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> bin(n);
		for (int i = 0; i < n; i++) {
			cin >> bin[i];
		}
		vector<int>ans(n + 1, 0);
		if (bin[n - 1] == 0) {
			for (int i = 0; i <= n; i++)ans[i] = i + 1;
		} else if (bin[0] == 1) {
			ans[0] = n + 1;
			for (int i = 1; i <= n; i++)ans[i] = i;
		}  else {
			int prev = 0, cur = 0;
			for (int i = 0; i < n ; i++) {
				if (prev == 0 && bin[i] == 1) {
					ans[i] = n + 1;
					prev = i + 1;
					break;
				}
				// } else if (prev == 0)ans[i] = i + 1;
				else ans[i] = i + 1;
			}
			for (int i = prev; i <= n; i++) {
				ans[i] = i;
			}
		}
		for (int i = 0; i <= n; i++)cout << ans[i] << " ";
		cout <<  "\n";
	}
	return 0;
}