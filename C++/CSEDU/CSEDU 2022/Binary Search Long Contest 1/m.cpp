#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n, t, k;
	cin >> n >> t >> k;
	int lo = 1, hi = n, mid;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (lo == hi) {
			cout << "? " << lo << " " << lo << endl;
			int input;
			cin >> input;
			if (input == 0) {
				cout << "! " <<  lo << endl;
				break;
			}
		}
		cout << "? " << lo << " " << mid << endl;
		int sum;
		cin >> sum;
		if (sum == -1)break;
		if ((mid - lo + 1) - sum >= k) {
			hi = mid;
		} else {
			k -= (mid - lo + 1) - sum;
			lo = mid + 1;
		}
	}
	return 0;
}