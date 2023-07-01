#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	int n, t, k;
	cin >> n >> t >> k;
	int lo = 1, hi = n, mid;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (lo == hi) {
			cout << "? " << lo << " " << lo << endl;
			int ans;
			cin >> ans;
			if (ans == 0) {
				cout << "! " <<  lo << endl;
				return 0;
			}
		}
		cout << "? " << lo << " " << mid << endl;
		int sum;
		cin >> sum;
		if (sum == -1)return 0;
		if ((mid - lo + 1) - sum >= k) {
			hi = mid;
		} else {
			k -= (mid - lo + 1) - sum;
			lo = mid + 1;
		}
	}
	return 0;
}