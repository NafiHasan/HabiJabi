#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	// fast_io();
	while (1) {
		int n;
		cin >> n;
		if (feof(stdin))break;
		vector<int> a(n);
		map<int, int> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			m[a[i]]++;
		}
		if (n == 1) {
			cout << a[0] << " 1 1\n";
			continue;
		}
		sort(a.begin(), a.end());
		if (n % 2) {
			cout << a[n / 2] << ' ' << m[a[n / 2]] << " 1\n";
			continue;
		}
		int ty = 1;
		int mid = n / 2;
		int cnt = m[a[mid]];
		if (n % 2 == 0) {
			mid--;
			if (a[mid] != a[mid + 1])cnt += m[a[mid]];
			ty = a[mid + 1] - a[mid] + 1;
		}
		cout << a[mid] << ' ' << cnt << ' ' << ty << '\n';
	}
	return 0;
}