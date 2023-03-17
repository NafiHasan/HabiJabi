#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	long long n, a , b;
	cin >> n >> a >> b;
	long long com = (a * b ) / __gcd(a, b);
	long long sum = n * (n + 1) / 2LL;
	long long cnta = n / a, cntb = n / b, cntab = n / com;
	sum -= (cnta * (cnta + 1) / 2LL) * a;
	sum -= (cntb * (cntb + 1) / 2LL) * b;
	sum += (cntab * (cntab + 1) / 2LL) * com;
	cout << sum << '\n';
	return 0;
}