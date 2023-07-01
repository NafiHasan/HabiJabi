#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		map<pair<int, char>, int>init, final;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				init[ {j, s[j]}]++;
			}
		}
		for (int i = 0; i < n - 1; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				final[ {j, s[j]}]++;
			}
		}
		string ans = "";
		for (int i = 0; i < m; i++) {
			for (char j = 'a'; j <= 'z'; j++) {
				if (init[ {i, j}] > final[ {i, j}]) {
					ans += j;
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}