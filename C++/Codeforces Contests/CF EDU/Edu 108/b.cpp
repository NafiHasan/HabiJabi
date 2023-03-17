#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	w(t) {
		int n, m, k;
		cin >> n >> m >> k;
		int ans = n * m;
		ans--;
		if (ans == k) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}