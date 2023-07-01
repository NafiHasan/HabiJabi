#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	int n;
	cin >> n;
	ll a[n];
	priority_queue<ll, vector<ll>, greater<ll>>minus;
	for (int i = 0; i < n; i++) cin >> a[i];
	ll mn = LLONG_MAX, now = 0;
	int ans = 0;
	for (int i = 0, j = 0; i < n; i++) {
		now += a[i];
		if (a[i] < 0)minus.push(a[i]);
		while (now < 0) {
			ans++;
			ll topp = minus.top();
			minus.pop();
			now -= topp;
		}
	}
	cout << n - ans << en;
	return 0;
}