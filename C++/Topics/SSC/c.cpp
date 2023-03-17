#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int n;
	cin >> n ;
	double dru;
	cin >> dru;
	int ind = -1;
	double tot = 0;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		tot += (x * y / 100.0);
		if ((tot - dru) > 1e-9 && ind == -1)ind = i + 1;
	}
	cout << ind << '\n';
	return 0;
}