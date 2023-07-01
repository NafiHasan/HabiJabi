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
		int a[n], sz = 0;
		vector<int>m(n + 1, 0), pos(n + 1);
		vector<int>v[n + 1], ans(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			m[a[i]]++;
			if (m[a[i]] == 1) {
				ans[i] = a[i];
				pos[a[i]] = i;
				sz++;
			}
		}
		vector<int>rem;
		for (int i = 0; i < n; i++) {
			if (m[i + 1] == 0) {
				rem.push_back(i + 1);
				// cout << i + 1 << "\n ";
			}
		}
		for (int i = 0; i < n; i++) {
			if (ans[i] == 0) {
				ans[i] = rem.back();
				rem.pop_back();
				if (ans[i] == i + 1) {
					ans[pos[a[i]]] = i + 1;
					ans[i] = a[i];
				}
			}
		}
		cout << sz << "\n";
		for (int i = 0; i < n; i++)cout << ans[i] << " ";
		cout << "\n";
	}
	return 0;
}