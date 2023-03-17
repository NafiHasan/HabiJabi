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
		vector<int> a(n);
		int num = 1;
		for (int i = 1; i < n; i += 2) {
			a[i] = num;
			num++;
		}
		num = n;
		for (int i = 0; i < n; i += 2) {
			a[i] = num;
			num--;
		}
		for (int i = 0; i < n; i++)cout << a[i] << ' ' ;
		cout << '\n';
	}
	return 0;
}