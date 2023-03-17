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
		vector<long long> a;
		map<long long, long long> mp;
		long long p = 1;
		int cnt = 0;
		for (long long i = 1; i <= n; i++) {
			for (long long j = i; j <= n; j *= 2) {
				if (mp[j] == 0)a.push_back(j);
				mp[j]++;
			}
		}
		// while (p <= n) {
		// 	a.push_back(p);
		// 	mp[p]++;
		// 	cnt++;
		// 	p *= 2;
		// }
		for (int i = 2; i <= n; i++) {
			if (mp[i] == 0) {
				a.push_back(i);
			}
		}
		cout << "2\n";
		for (int i = 0; i < a.size(); i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';

	}
	return 0;
}