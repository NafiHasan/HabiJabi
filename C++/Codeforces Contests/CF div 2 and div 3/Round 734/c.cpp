#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<string>v(n);
		map<char, int>m;
		char best;
		int mx = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			for (int j = 0; j < v[i].size() ; j++) {
				m[v[i][j]]++;
				// if (m[v[i][j]] > mx) {
				// 	mx = m[v[i][j]];
				// 	best = v[i][j];
				// }
			}
		}
		map<pair<int, char>, int, greater<int>>dif;
		map<pair<int, char>, int> :: iterator it;
		for (int j = 'a' ; j <= 'z' ; j++) {
			for (int i = 0; i < n; i++) {
				int tot = 0, cur = 0;
				for (int j = 0; j < v[i].size(); j++) {
					if (v[i][j] == j)cur++;
					else tot++;
				}
				dif[ {i, j}] = cur - tot;
			}
		}
		sort(dif.rbegin(), dif.rend());
		int adv = 0, ans = 0;
		// for (int i = 0; i < n; i++)cout << dif[i].second << "\n";
		for (int j = 'a'; j <= 'z' ; j++) {
			int now  = 0, adv = 0;
			for (int i = 0 ; i < n; i++) {
				if (dif[i].first > 0) {
					now++;
					adv += dif[i].first;
				} else if (dif[i].first + adv > 0) {
					ans++;
					adv = adv + dif[i].first;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}