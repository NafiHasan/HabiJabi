#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, x;
		cin >> n >> x;
		int a[n], sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		sort(a, a + n);
		if (sum == x)cout << "NO\n";
		else {
			int tmp = 0;
			for (int i = 0; i < n; i++) {
				tmp += a[i];
				if (tmp == x) {
					swap(a[i], a[n - 1]);
					break;
				}
			}
			cout << "YES\n";
			for (int i = 0; i < n; i++)cout << a[i] << " ";
			cout << en;
		}
	}
	return 0;
}