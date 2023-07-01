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
		vector<ll>a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		cout << n * 3 << en;
		for (int i = 0; i < n; i += 2) {
			cout << 1 << " " << i + 1 << " " << i + 2 << en;
			cout << 2 << " " << i + 1 << " " << i + 2 << en;
			cout << 1 << " " << i + 1 << " " << i + 2 << en;
			cout << 1 << " " << i + 1 << " " << i + 2 << en;
			cout << 2 << " " << i + 1 << " " << i + 2 << en;
			cout << 1 << " " << i + 1 << " " << i + 2 << en;
		}
	}
	return 0;
}