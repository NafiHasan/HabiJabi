#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	while (1) {
		double l, w;
		cin >> l >> w;
		if (l == 0)break;
		double mny = (2.0 * w - l) / 2.0;
		double x = (l * l + w * w - (2.0 * w * mny) + mny * mny) / (2.0 * l);
		cout << fixed << setprecision(4) << (x * 2.0 + mny) << '\n';
	}
	return 0;
}
