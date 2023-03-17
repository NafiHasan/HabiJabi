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
		vector<string> v(n);
		map<char, int> mp;
		string ans = "";
		map<char, int> added;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			mp[v[i][0]]++;
			if (mp[v[i][0]] > 2 && added[v[i][0]] == 0) {
				ans += v[i][0];
				added[v[i][0]]++;
			}
		}
		if (ans.size() == 0)cout << "impossible\n";
		else {
			sort(ans.begin(), ans.end());
			cout << ans << '\n';
		}
	}
	return 0;
}