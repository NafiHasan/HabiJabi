#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	long long n;
	cin >> n;
	long long sum = n * (n + 1) / 2LL;
	cout << (sum % 2LL ) << '\n';
	return 0;
}