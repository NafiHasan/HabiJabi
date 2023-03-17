#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


const double pi = 2.0 * acos(0.0);

int main() {
	FastIO;
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case " << cs << ": ";
		double r;
		cin >> r;
		double area = (2.0 * r ) * (2.0 * r);
		area -= pi * r * r;
		cout << fixed << setprecision(2) << area << '\n';
	}
	return 0;
}