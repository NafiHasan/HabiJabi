#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n), ind[n + 1], num;
		map<int, int> mp;
		long long ans = 0;
		for (int i = 0 ; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
			if (mp[a[i]] == 1)num.push_back(a[i]);
			ind[a[i]].push_back(i);
		}
		for (int i = 0; i < num.size(); i++) {
			int prev = -1;
			for (int j = 0; j < ind[num[i]].size(); j++) {
				int acp = min(ind[num[i]][j], n - num[i]);
				int now2 = min(num[i], ind[num[i]][j] + 1);
				if (prev > -1)
					now2 = max(0, acp - prev);
				now2 = min(now2, n - num[i] + 1);
				now2 = min(now2, n - ind[num[i]][j]);
				now2 = min(now2, num[i]);
				ans += now2;
				prev = ind[num[i]][j];
				if (prev + num[i] - 1 > n)prev = n - num[i] + 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}