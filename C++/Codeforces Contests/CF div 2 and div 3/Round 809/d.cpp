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
		vector<int> a(n);
		int mn = 300000000, mx = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mx = max(mx, a[i]);
			mn = min(mn, a[i]);
		}
		int min_s = 10000000;


		for (int kk = 1; kk <= k; kk++) {
			int s2 = mx / kk;
			int s2_ = s2 <= 0 ? 1 : s2;
			int k_ = mn / s2_;
			if (k_ < 1)
				k_ = 1;
			if (k_ > k)
				k_ = k;
			int s1 = mn / k_;
			if (abs(s2 - s2) < min_s)
				min_s = abs(s2 - s1);

		}
		cout << min_s << '\n';
	}
	return 0;
}


// 2, 4  || 2, 5 || 3,6 || 4, 8 || 5, 11