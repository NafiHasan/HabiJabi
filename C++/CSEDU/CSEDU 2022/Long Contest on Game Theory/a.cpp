#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case " << cs << ": ";
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int i = 0; i < n; i++)cin >> b[i];
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt = cnt ^ (abs(a[i] - b[i]) - 1);
		}
		if (cnt == 0)cout << "black wins\n";
		else cout << "white wins\n";
	}
	return 0;
}