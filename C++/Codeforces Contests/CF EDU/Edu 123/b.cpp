#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int cnt = 0;
		vector<int> a(n);
		for (int i = 0; i < n; i++)a[i] = i + 1;
		reverse(a.begin(), a.end());
		for (int i = 0; i < n; i++)cout << a[i] << ' ';
		cout << "\n";
		for (int i = 0; i < n - 1; i++) {
			swap(a[i], a[i + 1]);
			for (int j = 0; j < n; j++)cout << a[j] << ' ';
			cout << "\n";
			swap(a[i], a[i + 1]);
		}
	}
	return 0;
}