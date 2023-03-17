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
		map<int, int> mp;
		bool ans = 1;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			mp[x]++;
			if (mp[x] > 2)ans = 0;
		}
		if (2 * k < n) {
			ans = 0;
		}
		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}