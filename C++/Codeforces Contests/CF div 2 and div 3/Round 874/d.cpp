#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc; cin >> tc;
	while (tc--) {
		int n;
		cin >> n; vector<int> a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		if (n == 1) {
			cout << "1\n";
			continue;
		}
		int mx = 0, mxInd = -1;
		for (int i = 1; i < n; i++) {
			if (a[i] > mx) {
				mx = a[i];
				mxInd = i;
			}
		}
		int l = mxInd - 1, r = mxInd - 1;
		for (int i = mxInd - 2; i >= 0; i--) {
			if (a[i] >= a[0])l = i;
			else break;
		}
		vector<int> ans, ans2;
		for (int i = mxInd; i < n; i++)ans.push_back(a[i]);
		for (int i = r; i >= l; i--)ans.push_back(a[i]);
		for (int i = 0; i < l; i++)ans.push_back(a[i]);
		if (mxInd == n - 1) {
			ans2.push_back(a[n - 1]);
			for (int i = 0; i < n - 1; i++)ans2.push_back(a[i]);
			if (ans2 > ans)ans = ans2;
		}
		for (int i = 0; i < n; i++)cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}