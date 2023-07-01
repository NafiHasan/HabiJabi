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
		vector<int> a(n);
		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
		}
		int last = 0;
		for (int i = 0; i < n; i++) {
			if (mp[a[i]] > 1) {
				last = i + 1;
				mp[a[i]]--;
			}
		}
		cout << last  << '\n';
	}
	return 0;
}