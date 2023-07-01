#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		map<string, int> mp;
		int ans = 0;
		for (int i = 0; i < n - 1; i++) {
			if (mp[s.substr(i, 2)] == 0) {
				mp[s.substr(i, 2)]++;
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}