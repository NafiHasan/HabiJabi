#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

double inc = .1;
int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n), tmp(n + 2, 0);
		for (int i = 0; i < n; i++)cin >> a[i];
		double now = 1;
		if (a[0] == 0) {
			tmp[0] = 1;
			tmp[1] = 2;
			tmp[2] = 3;
		} else if (a[0] == 1) {
			tmp[0] = 2;
			tmp[1] = 1;
			tmp[2] = 3;
		} else if (a[0] == 2) {
			tmp[0] = 3;
			tmp[1] = 1;
			tmp[2] = 2;
		} else {
			tmp[0] = 3;
			tmp[1] = 2;
			tmp[2] = 1;
		}
		bool ans = 1;
		for (int i = 1, j = 3; i < n; j++, i++) {
			if (a[i] == 0) {
				if (tmp[j - 2] > tmp[j - 1]) {
					ans = 0;
					break;
				}
				tmp[j - 2] = 1;
				tmp[j - 1] = 2;
				tmp[j] = 3;
			} else if (a[i] == 1) {
				if (tmp[i + 1] > tmp[i]) {
					tmp[j - 2] = 1;
					tmp[j - 1] = 3;
					tmp[j] = 2;
				} else {
					tmp[j - 2] = 2;
					tmp[j - 1] = 1;
					tmp[j] = 3;
				}
			} else if (a[i] == 2) {
				if (tmp[i + 1] > tmp[i]) {
					tmp[j - 2] = 2;
					tmp[j - 1] = 3;
					tmp[j] = 1;
				} else {
					tmp[j - 2] = 3;
					tmp[j - 1] = 1;
					tmp[j] = 2;
				}
			} else {
				if (tmp[i + 1] < tmp[i]) {
					tmp[j - 2] = 1;
					tmp[j - 1] = 2;
					tmp[j] = 3;
				} else {
					ans = 0;
					break;
				}
			}
		}
		// for (int i = 0; i < n + 2; i++)cout << tmp [i] << ' ';
		// cout << "\n";
		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}