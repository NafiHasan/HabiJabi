#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		// deque<char> d;
		string s;
		cin >> s;
		// for (int i = 0; i < ss.size(); i++)d.push_back(ss[i]);
		// while (d.back() == '0')d.pop_back();
		// while (d.front() == '0')d.pop_front();
		// string s;
		// for (int i = 0; i < d.size(); i++)s.push_back(d[i]);
		int n = s.size();
		// cout << s << '\n';
		int one = 0, z = 0;

		while (!s.empty() && s.back() == '0')s.pop_back();
		reverse(s.begin(), s.end());
		while (!s.empty() && s.back() == '0')s.pop_back();
		reverse(s.begin(), s.end());
		n = s.size();
		for (int i = 0; i < n; i++) {
			if (s[i] == '1')one++;
			else z++;
		}
		// vector<int> dp(n, z);
		int ans = z, tone = 0, tz = z;
		int l1 = 0, r1 = 0, l2 = 0, r2 = 0, ind1 = 0, ind2 = 0;
		for (int i = 0 ; i < n; i++) {
			if (s[i] == '1')tone++;
			else tz--;
			if (max(tone, tz) < ans) {
				l1 = tz;
				r1 = tone;
				ans = max(tone, tz);
				ind1 = i;
			}
			// dp[i] = min(dp[i], max(tone, tz));
		}
		int tans = z;
		tone = 0, tz = z;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == '1')tone++;
			else tz--;
			if (max(tone, tz) < tans) {
				tans = max(tone, tz);
				l2 = tz;
				r2 = tone;
				ind2 = i;
			}
			// dp[i] = min(dp[i], max(tone, tz));
		}
		// for (int i = 0; i < n ; i++)ans = min(ans, dp[i]);
		ans = min(ans, tans);
		if (ind1 < ind2) {
			ans = min(ans, max(z - (l1 + l2), r1 + r2));
		}
		cout << ans << '\n';


	}
	return 0;
}