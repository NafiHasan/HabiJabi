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
		int a[n];
		for (int i = 0; i < n; i++)cin >> a[i];
		vector<int>ans;
		ans.push_back(0);
		for (int i = 1; i < n; i++) {
			if ((a[i] & a[i - 1]) != a[i - 1]) {
				int num = 0;
				for (int j = 0; j < 31; j++) {
					if (((1 << j) & a[i - 1]) == (1 << j) && ((1 << j ) & a[i]) == 0) {
						num = (num ^ (1 << j));
						// cout << num << en << (1 << j) << en;
					}
				}
				ans.push_back(num);
				a[i] ^= num;
				// cout << a[i] << " end\n";
			} else ans.push_back(0);
		}
		for (int i = 0; i < ans.size(); i++)cout << ans[i] << " ";
		cout << "\n";
	}
	return 0;
}