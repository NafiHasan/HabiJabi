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
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int i = 0; i < n; i++) {
			if (a[i] == i + 1)continue;
			int f = i + 1;
			for (int j = i + 1; j < n; j++) {
				if (a[j] == f) {
					reverse(a.begin() + i, a.begin() + j + 1);
					i = n;
					break;
				}
			}
		}
		for (int i = 0; i < n; i++)cout << a[i] << ' ';
		cout << '\n';
	}
	return 0;
}