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
		vector<long long> a(n);
		map<long long, long long> mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
		}
		sort(a.begin(), a.end());
		if (mp[a[n - 2] + a[n - 1] + a[n - 3]] > 0LL && mp[a[0] + a[1] + a[2]] > 0LL && mp[a[0] + a[1] + a[n - 1]] > 0 && mp[a[0] + a[n - 1] + a[n - 2]] > 0)cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}