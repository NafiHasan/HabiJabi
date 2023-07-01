#include <bits/stdc++.h>

using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		int ind1, ind2, dif = INT_MAX;
		for (int i = n - 1; i > 0; i--) {
			if (a[i] - a[i - 1] < dif) {
				dif = a[i] - a[i - 1];
				ind1 = i - 1, ind2 = i;
			}
		}
		cout << a[ind1] << " " ;
		for (int i = ind2 + 1; i < n; i++) cout << a[i] << " ";
		for (int i = 0; i < ind1 ; i++) cout << a[i] << " " ;
		cout << a[ind2] << "\n";
	}
	return 0;
}