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
		sort(a, a + n);
		if (a[0] < 0) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		cout << 101 << en;
		for (int i = 0; i <= 100; i++)cout << i << " ";
		cout << en;
	}
	return 0;
}