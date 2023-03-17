#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int g =  a[0];
		for (int i = 1; i < n; i++)g = __gcd(g, a[i]);
		long long ans = (long long)g * (long long)n;
		cout << ans << '\n';
	}
	return 0;
}