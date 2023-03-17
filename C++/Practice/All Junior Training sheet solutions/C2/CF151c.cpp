#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

int main() {
	FastIO;
	ll n;
	cin >> n;
	ll cnt = 0, div1 = -1, div2 = -1;
	for (ll i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			cnt++;
			if (div1 == -1) div1 = i;
			else if (div2 == -1)div2 = i;
			n /= i;
		}
	}
	if (n != 1)cnt++;
	if (cnt == 2) {
		cout << "2\n";
	} else {
		if (cnt == 1 || div1 == -1) {
			cout << "1\n0\n";
		} else {
			cout << "1\n" << (div1 * div2) << "\n";
		}
	}
	return 0;
}