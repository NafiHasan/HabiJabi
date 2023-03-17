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
		int a[n];
		for (int i = 0; i < n; i++)cin >> a[i];
		vector<int>v;
		for (int i = 0; i < n; i++) {
			if (a[i] % 2 == 0)v.push_back(a[i]);
		}
		for (int i = 0; i < n; i++) {
			if (a[i] % 2 == 1)v.push_back(a[i]);
		}
		int ans = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (__gcd(v[i], v[j] * 2) > 1)ans++;
			}
		}
		cout << ans << en;
	}
	return 0;
}