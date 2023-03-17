#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

map<int, int> fr;
// bool comp(int x, int y) {
// 	if (fr[x] <= fr[y])return x <= y;
// 	return x > y;
// }


int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		fr.clear();
		int n;
		cin >> n;
		vector<int> a(n);
		bool ok = 1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			fr[a[i]]++;
			if (fr[a[i]] > (n / 2))ok = 0;
		}
		if (!ok) {
			cout << "NO\n";
			continue;
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++)cout << a[i] << ' ' ;
		cout << "\n";
		vector<int> b = a;
		for (int i = 0; i < n; i++) {
			if (b[i] != a[i])continue;
			for (int j = 0; j < n; j++) {
				if (a[i] != b[j]) {
					swap(b[i], b[j]);
					break;
				}
			}
		}
		for (int i = 0; i < n; i++)cout << b[i] << ' ';
		cout << "\n";
	}
	return 0;
}