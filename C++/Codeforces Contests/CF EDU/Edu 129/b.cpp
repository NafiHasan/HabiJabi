#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		long long n, m;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		cin >> m;
		long long sum = 0;
		vector<long long> b(m);
		for (int i = 0 ; i < m; i++) {
			cin >> b[i];
			sum += b[i];
		}
		cout << a[sum % n] << '\n';
	}
	return 0;
}