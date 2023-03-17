#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		int ind = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] != -1)ind = i;
		}
		for (int i = ind - 1; i >= 0; i--) {
			if (a[i] == -1) {
				a[i] = a[i + 1] - 1 + m;
				a[i] %= m;
			}
		}
		for (int i = ind + 1; i < n; i++) {
			if (a[i] == -1) {
				a[i] = (a[i - 1] + 1) % m;
			}
		}
		for (int i = 0; i < n; i++)cout << a[i] << ' ';
		cout << "\n";
	}
	return 0;
}