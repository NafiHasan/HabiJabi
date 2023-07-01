#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	int n = 300000;
	cout << "1\n\n300000 300000\n";
	for (int i = 1; i <= n; i++) {
		if (i > 1)cout << " ";
		cout << i;
	}
	cout << endl;
	for (int i = 1; i <= n; i++) {
		if (i > 1)cout << " ";
		cout << i;
	}
	cout << endl;
	return 0;
}