#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++)cin >> a[i];
	long long g = a[0];
	for (int i = 1; i < n; i++) {
		g = __gcd(g, a[i]);
	}
	long long cnt = 0;
	for (long long i = 1; i * i <= g; i++) {
		if (g % i == 0)cnt++;
		if (i != (g / i) && g % i == 0)cnt++;
	}
	cout << cnt << '\n';
	return 0;
}