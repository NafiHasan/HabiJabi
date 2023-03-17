#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case " << cs << ": ";
		long long a[3];
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3);
		if (a[1] * a[1] + a[0] * a[0] == a[2] * a[2])cout << "yes\n";
		else cout << "no\n";

	}
	return 0;
}