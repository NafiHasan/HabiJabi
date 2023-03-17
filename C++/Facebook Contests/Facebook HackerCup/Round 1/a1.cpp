#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case #" << cs << ": ";
		int n, k;
		cin >> n >> k;
		vector<int> a(n), b(n), part1, part2;
		map<int, int> mp;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]] = i + 1;
		}
		for (int i = 0; i < n; i++)cin >> b[i];

		int f = -1;
		for (int i = 0; i < n; i++) {
			if (f == -1) {
				if (b[i] == a[0]) {
					f = i;
					part1.push_back(b[i]);
				} else {
					part2.push_back(b[i]);
				}
			} else part1.push_back(b[i]);
		}
		for (int i = 0; i < part2.size(); i++)part1.push_back(part2[i]);

		if (f != 0 && k == 0) {
			cout << "NO\n";
			continue;
		}
		if (f == 0 && n == 2 && (k % 2 == 1)) {
			cout << "NO\n";
			continue;
		}
		if (f != 0 && n == 2 && (k % 2 == 0)) {
			cout << "NO\n";
			continue;
		}
		if (f == 0 && k == 1) {
			cout << "NO\n";
			continue;
		}
		bool ok = 1;
		for (int i = 1; i < n; i++) {
			if (mp[part1[i]] != (mp[part1[i - 1]] + 1)) {
				ok = 0;
				break;
			}
		}
		if (ok)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}