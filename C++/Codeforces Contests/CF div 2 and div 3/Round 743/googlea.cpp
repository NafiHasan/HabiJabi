#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		int n;
		string s;
		cin >> n >> s;
		vector<int>tr;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1')tr.push_back(i);
		}
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1')continue;
			int lo = 0 , hi = tr.size() - 1, mid;
			int close1 = INT_MAX;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (tr[mid] < i) {
					close1 = tr[mid];
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			lo = 0, hi = tr.size() - 1;
			int close2 = INT_MAX;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (tr[mid] > i) {
					close2 = tr[mid];
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}
			// cout << i << ' ' << close1 << ' ' << close2 << '\n';
			ans += (long long)min(abs(i - close1), abs(i - close2));
		}
		cout << "Case #" << cs << ": " << ans << '\n';
	}
	return 0;
}