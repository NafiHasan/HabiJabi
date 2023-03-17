#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	w(t) {
		int a[4];
		cin >> a[0] >> a[1] >> a[2] >> a[3];
		int mx = max(a[0], a[1]), mx2 = max(a[2], a[3]);
		sort(a, a + 4);
		if (mx == a[2] && mx2 == a[3])cout << "YES\n";
		else if (mx == a[3] && mx2 == a[2])cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}