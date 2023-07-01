#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	long long lo = 3, hi = 1e18, mid, ans = 3;
	cout << "? 1 " << hi << endl;
	long long got;
	cin >> got;
	if (got == -1) {
		hi--;
	} else {
		cout << hi << endl;
		return 0;
	}
	while (lo <= hi) {
		mid = (lo + hi) / 2LL;
		cout << "? 1 " << mid << endl;
		long long got;
		cin >> got;
		if (got == -1) {
			hi = mid - 1;
		} else {
			lo = max(got, mid + 1);
			ans = max(ans, mid);
		}
	}
	cout << "! " << ans << endl;
	return 0;
}