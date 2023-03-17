#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case " << cs << ": ";
		int r1, c1 , r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		if (((r1 + c1) % 2) != ((r2 + c2) % 2)) {
			cout << "impossible\n";
			continue;
		} else {
			if (abs(r1 - r2) == abs(c1 - c2)) {
				cout << "1\n";
			} else cout << "2\n";
		}
	}
	return 0;
}