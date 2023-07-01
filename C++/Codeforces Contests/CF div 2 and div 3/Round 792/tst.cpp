#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	for (int i = 0 ; i < 20; i++) {
		cout << i << ' ' << (6 ^ i) << '\n';
	}
	return 0;
}