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
		int n = s.size();
		int one = 0, zero = 0;

		while (!s.empty() && s.back() == '0')s.pop_back();
		reverse(s.begin(), s.end());
		while (!s.empty() && s.back() == '0')s.pop_back();
		reverse(s.begin(), s.end());
		n = s.size();
		vector<int> pre1(n + 1, 0), pre0(n + 1, 0);
		for (int i = n - 1, j = 0; i >= 0; j++, i--) {
			if (s[i] == '1')one++;
			else zero++;
			pre1[j + 1] = one;
			pre0[j + 1] = zero;
		}
		int ans = zero;
		int tot = zero;
		one = 0, zero = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1')one++;
			else zero++;
			// cout << i << ' ' << zero << ' ' << one << '\n';
			int lo = 0, hi = n - i - 1 , mid;
			if (i == 0) {
				while (lo <= hi) {
					mid = (lo + hi) / 2;
					int cnt1 = pre1[mid];
					int cnt0 = tot - pre0[mid];
					ans = min(ans, max(cnt1, cnt0));
					if (cnt1 >= cnt0) {
						hi = mid - 1;
					} else lo = mid + 1;
				}
			}
			lo = 0, hi = n - i - 1;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				int cnt1 = one + pre1[mid];
				int cnt0 = tot - zero - pre0[mid];
				ans = min(ans, max(cnt1, cnt0));
				if (cnt1 >= cnt0) {
					hi = mid - 1;
				} else lo = mid + 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}