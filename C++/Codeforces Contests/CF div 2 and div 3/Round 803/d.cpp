#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int query(int lo, int hi) {
	cout << "? " <<  lo + 1 << ' ' << hi + 1 << endl;
	int k = (hi - lo + 1);
	vector<int> a(k);
	for (int i = 0; i < k; i++)cin >> a[i];
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		if (a[i] >= (lo + 1) && a[i] <= (hi + 1))cnt++;
	}
	return cnt;
}


int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int lo = 0, hi = n - 1, mid = (lo + hi) / 2;
		int got;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			got = query(lo, mid);
			if (got % 2 == 1) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		cout << "! " << lo + 1 << endl;
	}
	return 0;
}