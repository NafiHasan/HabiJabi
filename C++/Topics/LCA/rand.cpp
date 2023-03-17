#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int n;
	cin >> n;
	cout << n << '\n';
	for (int i = 0; i < n - 1; i++) {
		int u = rand() % n;
		int v = rand() % n;
		int w = rand();
		while (v == u)v = rand() % n;
		cout << u + 1 << ' ' << v + 1 << ' ' << w << '\n';
	}
	return 0;
}