#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool chk2(pair<int, int> a, pair<int, int> b, pair<int, int> c, int n) {
	vector<pair<int, int>> vp;
	vp.push_back(a);
	vp.push_back(b);
	vp.push_back(c);
	sort(vp.begin(), vp.end());
	pair<int, int> p1 = {1, 1}, p2 = {1, 2}, p3 = {2, 1}, p4 = {n - 1,  1}, p5 = {n , 1}, p6 = {n, 2}, p7 = {n - 1, n}, p8 = {n, n - 1}, p9 = {n, n}, p10 = {1, n - 1}, p11 = {1, n}, p12 = {2, n};
	if (vp[0] == p1 && vp[1] == p2 && vp[2] == p3)return 1;
	if (vp[0] == p4 && vp[1] == p5 && vp[2] == p6 )return 1;
	if (vp[0] == p7 && vp[1] == p8 && vp[2] == p9 )return 1;
	if (vp[0] ==  p10 && vp[1] == p11 && vp[2] == p12 )return 1;
	return 0;
}


bool chk(pair<int, int> a, pair<int, int> b, pair<int, int> c, int n, int t1, int t2) {
	vector<pair<int, int>> vp;
	vp.push_back(a);
	vp.push_back(b);
	vp.push_back(c);
	sort(vp.begin(), vp.end());
	pair<int, int> p1 = {1, 1}, p2 = {1, 2}, p3 = {2, 1}, p4 = {n - 1,  1}, p5 = {n , 1}, p6 = {n, 2}, p7 = {n - 1, n}, p8 = {n, n - 1}, p9 = {n, n}, p10 = {1, n - 1}, p11 = {1, n}, p12 = {2, n};
	if (vp[0] == p1 && vp[1] == p2 && vp[2] == p3 && (t1 == 1 || t2 == 1))return 1;
	if (vp[0] == p4 && vp[1] == p5 && vp[2] == p6 && (t1 == n || t2 == 1))return 1;
	if (vp[0] == p7 && vp[1] == p8 && vp[2] == p9 && (t1 == n || t2 == n))return 1;
	if (vp[0] ==  p10 && vp[1] == p11 && vp[2] == p12 && (t1 == 1 || t2 == n))return 1;
	return 0;
}


int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int r1, c1, r2, c2, r3, c3, t1, t2;
		cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3 >> t1 >> t2;
		if (chk2({r1, c1}, {r2, c2}, {r3, c3}, n)) {
			if (chk({r1, c1}, {r2, c2}, {r3, c3}, n, t1, t2))cout << "YES\n";
			else cout << "NO\n";
			continue;
		}
		if ((t1 % 2 == r1 % 2) && (t2 % 2 == c1 % 2))cout << "YES\n";
		else if ((t1 % 2 == r2 % 2) && (t2 % 2 == c2 % 2))cout << "YES\n";
		else if ((t1 % 2 == r3 % 2) && (t2 % 2 == c3 % 2))cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}