#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int oc(int n) {
	int bits = log2(n) + 1;
	return ((1 << bits) - 1) ^ n;
}

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i < n; i++)a[i] = i + 1;
		int bits = log2(n);
		int ans = 0;
		// if (x >= n) {
		int find = oc(x);
		// if (find > n) {
		// 	cout << "-1\n";
		// 	continue;
		// }
		int pre = 1;
		if (find == 1)pre = 2;
		vector<vector<int> > v(n - 1, vector<int> (3));
		for (int i = 1, j = 0; i < n; i++) {
			if (a[i] == find)continue;
			v[j][0] = 1, v[j][1] = pre , v[j++][2] = a[i];
			pre |= a[i];
		}
		if (find != 0) {
			v[n - 2] = {2, pre, find};
			if ((pre ^ find) != x) {
				cout << "-1\n";
				continue;
			}
		}
		for (int i = 0; i < n - 1; i++) {
			cout << v[i][0] << ' ' << v[i][1] <<  ' ' << v[i][2] << '\n';
		}
		// } else {
		// 	int f = ( 1 << bits);
		// 	// cout << f << '\n';
		// 	// if (f > n) {
		// 	// 	cout << "-1\n";
		// 	// 	continue;
		// 	// }
		// 	int fo = 0;
		// 	cout << "1 " << f << ' ';
		// 	if ((f - 1) != x) {
		// 		cout << f - 1 << '\n';
		// 		int pre = f | (f - 1);
		// 		int pre2 = 1;
		// 		for (int i = 1; i < n; i++) {
		// 			if (a[i] == x || a[i] == f || a[i] == f - 1)continue;
		// 			cout << "1 " << pre2 << ' ' << a[i] << '\n';
		// 			pre2 |= a[i];
		// 		}
		// 		cout << "2 " << pre << ' ' << pre2 << '\n';
		// 		cout << "1 " << (pre ^ pre2) << ' ' << x << '\n';
		// 	} else {
		// 		if (bits > 1) {
		// 			int f2 = (1 << (bits - 1));
		// 			cout << f2 << '\n';
		// 			int pre = f | (f - 1);
		// 			int pre2 = 1;
		// 			for (int i = 1; i < n; i++) {
		// 				if (a[i] == x || a[i] == f || a[i] == f - 1)continue;
		// 				cout << "1 " << pre2 << ' ' << a[i] << '\n';
		// 				pre2 |= a[i];
		// 			}
		// 			cout << "2 " << pre << ' ' << pre2 << '\n';
		// 			cout << "1 " << (pre ^ pre2) << ' ' << x << '\n';
		// 		}
		// 	}
		// }

	}
	return 0;
}