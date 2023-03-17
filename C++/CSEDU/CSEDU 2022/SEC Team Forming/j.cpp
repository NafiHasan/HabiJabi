#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n;
	cin >> n;
	vector<pair<long long, long long>>vp(n);
	for (int i = 0; i < n; i++)cin >> vp[i].first >> vp[i].second;
	int ans = 0;
	// cout << sqrt(2000000000000000000) << '\n';
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				// if (i == j || i == k || j == k)continue;
				bool ok = 1;
				long double  x1 = vp[i].first , y1 = vp[i].second;
				long double x2 = vp[j].first , y2 = vp[j].second;
				long double x3 = vp[k].first , y3 = vp[k].second;
				// long double a, b, c;
				long double ab = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
				ab = sqrtl(ab);
				long double bc = ((x3 - x2) * (x3 - x2)) + ((y3 - y2)  * (y3 - y2));
				bc = sqrtl(bc);
				long double ca = ((x1 - x3) * (x1 - x3)) + ((y1 - y3) * (y1 - y3));
				ca = sqrtl(ca);
				// cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << ' '  << ab << ' ' << bc << ' ' << ca << '\n';
				// cout << (x1 - x2) * (x1 - x2) << '\n';
				// cout << ab << ' ' << bc << ' ' << ca << '\n';
				// if ((long double)(ab + bc - ca) <= (long double)1e-18)ok = 0;
				// if ((long double)(ab + ca - bc) <= (long double)1e-18)ok = 0;
				// if ((long double)(bc + ca  - ab) <= (long double)1e-18)ok = 0;
				if (ab > bc)swap(ab, bc);
				if (ab > ca)swap(ab, ca);
				if (bc > ca)swap(bc, ca);
				if (ab + bc <= ca)ok = 0;
				// if ((a + b ) <= c)ok = 0;
				// if ((b + c) <= a)ok = 0;
				// if ((c + a ) <= b)ok = 0;
				// if (ab + bc + ca == 0)ok = 0;
				// if ((ab + bc) > ca && (ab + ca) > bc && (bc + ca) > ab)ok = 1;
				// else ok = 0;
				if (ok) {
					ans++;
					// cout << ab << ' ' << bc << ' ' << ca << '\n';
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}