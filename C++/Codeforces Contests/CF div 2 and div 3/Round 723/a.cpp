#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	w(t) {
		int n;
		cin >> n;
		n *= 2;
		int a[n];
		for (int i = 0; i < n; i++)cin >> a[i];
		sort(a, a + n);
		for (int i = 2; i < n; i += 2) {
			swap(a[i], a[i - 1]);
		}
		for (int i = 0; i < n; i++)cout << a[i] << " ";
		cout << en;
	}
	return 0;
}