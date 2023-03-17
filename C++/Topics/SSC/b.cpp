#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int n, s, d; cin >> n >> s >> d;
	bool ok = 0;
	for (int i = 0; i < n; i++) {
		int x, y ;
		cin >> x >> y;
		if (x < s && y > d)ok = 1;
	}
	if (ok)cout << "Yes\n";
	else cout << "No\n";
	return 0;
}