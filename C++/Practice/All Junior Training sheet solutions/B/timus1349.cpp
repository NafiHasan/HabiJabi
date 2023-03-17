#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
int main() {
	fast_io();
	ll n;
	cin >> n;
	if (n == 1) {
		cout << "1 2 3\n";
	} else if (n == 2) {
		cout  << "3 4 5\n";
	} else cout << "-1\n";
	return 0;
}