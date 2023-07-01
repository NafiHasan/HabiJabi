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
		int a[n], pos = 0, mn = INT_MAX;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (mn > a[i]) {
				mn = a[i];
				pos = i;
			}
		}
		vector<int>ans ;
		for (int i = 0; i < n; i++) {
			if (i == pos)continue;
			ans.push_back(i + 1);
			ans.push_back(pos + 1);
			ans.push_back(abs(pos - i) + a[pos]);
			ans.push_back(a[pos]);
		}
		cout << (int)ans.size() / 4 << en;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
			if (i % 4 == 3)cout << en;
		}
	}
	return 0;
}