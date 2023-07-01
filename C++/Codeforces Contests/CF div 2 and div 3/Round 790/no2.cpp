#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int main() {
	fast_io();
	int n;
	cin >> n;
	vector<long long> a(n);
	long long sum = 0, avg;
	for (int i = 0; i < n; i++) {
		cin >> a[i];

	}
	sort(a.begin(), a.end());
	long long ans = 0;
	for (long long i = 0; i < n; i++) {
		sum += a[i];
		avg = sum / (i + 1);
		long long lo = 0, hi = i, mid, ind;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (a[mid] <= avg)lo = mid + 1;
			else {
				ind = mid;
				hi = mid - 1;
			}
		}
		ans = max(ans, i - ind + 1LL);
	}
	cout << ans << '\n';
	return 0;
}