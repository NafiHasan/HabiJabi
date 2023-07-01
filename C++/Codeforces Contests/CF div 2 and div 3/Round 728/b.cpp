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
		long long n;
		cin >> n;
		long long a[n + 1];
		for (int i = 1; i <= n; i++)cin >> a[i];
		long long ans = 0;
		for (long long i = 1; i <= n; i++) {
			for (long long j = a[i] - i; j <= n; j += a[i]) {
				if (j > i && a[i]* a[j] == (i + j))ans++;
			}
		}
		cout << ans << en;
	}
	return 0;
}