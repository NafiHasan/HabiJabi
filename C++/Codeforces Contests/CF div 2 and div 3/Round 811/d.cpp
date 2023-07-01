#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		int n;
		cin >> n;
		vector<string> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		bool ans = 1;
		vector<pair<int, int>> all;
		for (int i = 0; i < s.size(); i++) {
			int mx = 0;
			pair<int, int> p;
			bool f = 0;
			for (int j = 0; j < n; j++) {
				for (int k = 0; k <= min(i, (int)s.size() - (int)a[j].size()); k++) {
					int mat = 0;
					if (s.substr(k, (int)a[j].size()) != a[j])continue;
					for (int l = k; l < (k + a[j].size()); l++)if (l >= i)mat++;
					if (mat > 0)f = 1;
					if (mx < mat) {
						p = {j + 1, k + 1};
						mx = mat;
					}
				}
			}

			if (f == 0) {
				ans = 0;
				break;
			}
			i += mx - 1;
			all.push_back(p);
		}
		if (ans == 1) {
			cout << all.size() << '\n';
			for (int i = 0; i < all.size(); i++)cout << all[i].first << ' ' << all[i].second << '\n';
		} else cout << "-1\n";
	}
	return 0;
}