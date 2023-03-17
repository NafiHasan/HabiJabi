#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			cout << i << ' ' << j << ' ' << (i & j) << '\n';
		}
	}
	return 0;
}