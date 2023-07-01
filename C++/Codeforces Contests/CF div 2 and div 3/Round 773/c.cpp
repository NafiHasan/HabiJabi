#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		long long int n, x;
		cin >> n >> x;
		multiset<long long> s;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			s.insert(v[i]);
		}
		sort(v.begin(), v.end());
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (s.find(v[i]) == s.end())continue;
			auto it = s.find(v[i]);
			s.erase(it);
			long long num = v[i] * x;
			if (s.find(num) != s.end()) {
				it = s.find(num);
				s.erase(it);
			} else cnt++;
			// for (auto it : s) {
			// 	cout << it << ' ';
			// }
			// cout << "\n";
		}
		cout << cnt << '\n';
	}
	return 0;
}