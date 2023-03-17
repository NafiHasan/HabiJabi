#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	w(t) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)cin >> a[i];
		if (a[0] == n && a[n - 1] == 1) {
			cout << "3\n";
			continue;
		}
		bool ys = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] != i + 1)ys = 1;
		}
		if (!ys) {
			cout << "0\n";
			continue;
		}
		if (a[n - 1] == n || a[0] == 1) {
			cout << "1\n";
			continue;
		}
		cout << "2\n";
	}
	return 0;
}