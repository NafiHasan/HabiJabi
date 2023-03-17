#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n,  k;
	cin >> n >> k;
	while (k--) {
		if (n % 10 == 0)n /= 10;
		else n--;
	}
	cout << n << '\n';
	return 0;
}