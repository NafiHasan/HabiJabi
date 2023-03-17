#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n;
	cin >> n;
	int a[n], ans[n];
	for (int i = 0; i < n; i++)cin >> a[i];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		ans[i] = a[i] / 2;
		sum += ans[i];
	}
	for (int i = 0 ; i < n; i++) {
		if (sum == 0)break;
		if (a[i] % 2) {
			// sum--;
			if (a[i] < 0) {
				ans[i]--;
				sum--;
			} else {
				ans[i]++;
				sum++;
			}
		}
	}
	for (int i = 0; i < n; i++)cout << ans[i] << "\n";
	return 0;
}