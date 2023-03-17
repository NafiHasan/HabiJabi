#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	bool ans = 1;
	int cnt = 0;
	map<int, int> mp;
	// int n = 20202021;
	// while (1) {
	// 	cout << n << '\n';
	// 	if (mp[n] > 1)break;
	// 	if (n % 2)n++;
	// 	else n /= 2;
	// 	mp[n]++;

	// 	cnt++;
	// }
	long long n = pow(2, 12);
	n += pow(3, 26);
	n += pow(5, 26);
	cout << LLONG_MAX - n << '\n';
	cout << __gcd(7LL, n) << '\n';
	return 0;
}