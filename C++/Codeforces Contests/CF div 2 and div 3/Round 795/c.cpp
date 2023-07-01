#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		string s; cin >> s;
		int fi = -1, la = -1;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == '1') {
				la = i;
				break;
			}
		}
		for (int i = 0; i < n - 1 ; i++) {
			if (s[i] == '1' && i != la) {
				fi = i;
				break;
			}
		}
		if (fi != -1 && la != -1) {
			if ((n - la - 1) <= k) {
				swap(s[n - 1], s[la]);
				k -= (n - la - 1);
			}
			if (fi <= k) {
				swap(s[fi], s[0]);
				k -= fi;
			}
		} else if (la != -1) {
			if ((n - la - 1) <= k) {
				swap(s[n - 1], s[la]);
				k -= (n - la - 1);
			} else if (la <= k) {
				swap(s[0], s[la]);
			}
		}
		long long ans = 0;
		for (int i = 0; i < n - 1; i++) {
			string tmp = s.substr(i, 2);
			ans += stoll(tmp);
		}
		cout << ans << '\n';
	}
	return 0;
}