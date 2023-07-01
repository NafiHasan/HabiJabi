#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		ll n, k, g;
		cin >> n >> k >> g;
		ll coins = k * g;
		ll div = (g - 1) / 2;
		ll save = min(k * g, (n - 1) * div);
		ll rem = coins - save;
		if (rem <= 0) {
			cout << k * g << '\n';
			continue;
		}
		ll giv;
		if ((rem % g) >= ((g + 1) / 2)) {
			giv = rem + g - (rem % g);
			save += rem - giv;
		} else {
			save += rem % g;
		}
		cout << max(0LL, save) << '\n';
	}
	return 0;
}