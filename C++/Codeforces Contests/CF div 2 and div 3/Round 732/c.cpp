#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<pair<int, int>> vp(n);
		vector<int>odd, even, sorted(n), check;
		for (int i = 0; i < n; i++) {
			cin >> vp[i].first;
			sorted[i] = vp[i].first;
			vp[i].second = i;
		}
		sort(sorted.begin(), sorted.end());
		// for (int i = 0; i < n; i++) {
		// 	cout << sorted[i] << " " << vp[i].first << "\n";
		// }
		int sz = 0;
		for (int i = 0; i < n; i++) {
			if (sorted[i] != vp[i].first) {
				check.push_back(vp[i].first);
				sz++;
				if (i % 2)odd.push_back(vp[i].first);
				else even.push_back(vp[i].first);
			}
		}
		sort(even.begin(), even.end());
		sort(odd.begin(), odd.end());
		sort(vp.begin(), vp.end());
		sort(check.begin(), check.end());
		// for (int i = 0; i < even.size(); i++)cout << even[i] << " ";
		bool ans = 1;
		for (int i = n - 1; i >= 0; i--) {
			if ((int)check.size() == 0)break;
			int las = check.back();

			if (las != vp[i].first) {
				continue;
			}
			check.pop_back();
			if (i % 2 == 0) {
				if (even.empty()) {
					ans = 0;
					break;
				}
				int last = even.back();
				if (vp[i].first != last) {
					ans = 0;
					break;
				} else even.pop_back();
			} else {
				// if (vp[i].first == 5)cout << vp[i].second << en;
				if (odd.empty()) {
					ans = 0;
					break;
				}
				int last = odd.back();
				// cout << last << " " << vp[i].first << en;
				if (vp[i].first != last) {
					ans = 0;
					break;
				} else odd.pop_back();
			}
		}
		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}