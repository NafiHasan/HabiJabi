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
		string s;
		cin >> s;
		vector<int> prep(n + 1, 0), prem(n + 1, 0);
		for (int i = 0; i < n; i++) {
			prep[i + 1] = prep[i];
			prem[i + 1] = prem[i];
			if (s[i] == '+')prep[i + 1]++;
			else prem[i + 1]++;
		}
		int ans = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				int cntp = prep[j + 1]  - prep[i];
				int cntm = prem[j + 1]  - prem[i];
				if (cntm == cntp || (cntm > cntp && (cntm - cntp) % 3 == 0))ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}