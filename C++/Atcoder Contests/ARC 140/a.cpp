#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int ans = INT_MAX;
	for (int i = 1; i <= n; i++) {
		if (n % i != 0)continue;
		vector<string> tmp;
		for (int j = 0; j < n ; j += i) {
			string st = s.substr(j, i);
			tmp.push_back(st);
		}
		int cnt = 0;
		for (int j = 0; j < tmp[0].size(); j++) {
			vector<int> al(27, 0);
			for (int k = 0; k < tmp.size(); k++) {
				al[tmp[k][j] - 'a']++;
			}
			sort(al.begin(), al.end());
			cnt += tmp.size() - al.back();
		}
		if (cnt <= k) {
			ans = min(ans, i);
		}
	}
	cout << ans << '\n';
	return 0;
}