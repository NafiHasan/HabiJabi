#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// int x, y , d, g;
// int egcd(int a, int b) {
// 	if (b == 0) {x = 1; y = 0; d = a; return a;}
// 	d = egcd(b, a % b);
// 	int x1 = y;
// 	int y1 = x - (a / b) * y;
// 	x = x1;
// 	y = y1;
// 	return d;
// }

// bool find(int a, int b, int c) {
// 	g = egcd(a, b);
// 	if (c % g)return 0;

// 	x = c / g;
// 	y = c / g;
// 	if (a < 0) x = -x;
// 	if (b < 0) y = -y;
// 	return 1;
// }

int gcd(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
	g = gcd(abs(a), abs(b), x0, y0);
	if (c % g) {
		return false;
	}

	x0 *= c / g;
	y0 *= c / g;
	if (a < 0) x0 = -x0;
	if (b < 0) y0 = -y0;
	return true;
}

int main() {
	FastIO;
	int x0, y0, g;
	if (find_any_solution(202, 303 , 606, x0, y0, g)) cout << x0 << ' ' << y0 << '\n';
	return 0;
}