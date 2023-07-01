#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int com(long long n, long long now) {
	string s1 = to_string(n), s2 = to_string(now);
	int ans = 0, same = 0;
	int ind = 0;
	for (int i = 0; i < s1.size(); i++) {
		for (int j = ind; j < s2.size(); j++) {
			if (s1[i] == s2[j]) {
				ind = j + 1;
				same++;
				break;
			} else break;
		}
	}
	int ad = (int)s1.size() - same;
	ans = (int)s2.size() - same + ad;
	return ans;
}

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		long long n;
		cin >> n;
		long long now = 1;
		int ans = 100;
		for (int i = 0; i < 60; i++) {
			// cout << now << "\n";
			ans = min(ans, com(n, now));
			// if (ans == 3) {
			// 	cout << n <<  " " << now << "\n";
			// }
			now *= 2;
		}
		cout << ans << "\n";
	}
	return 0;
}