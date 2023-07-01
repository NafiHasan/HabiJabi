#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		ll n, sum = 0;
		cin >> n;
		vector<ll> a(n);
		map<ll, ll>m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			m[a[i]]++;
			sum += a[i];
		}
		queue<ll> q;
		q.push(sum);
		int mx  = 0;
		while (!q.empty()) {
			mx = max(mx, (int)q.size());
			ll t = q.front();
			q.pop();
			if (m[t] > 0) {
				m[t]--;
				continue;
			}
			if (t <= 1)continue;
			q.push(t / 2);
			if (t % 2)q.push(t / 2 + 1);
			else q.push(t / 2);
		}
		bool ans = 1;
		for (int i = 0; i < n; i++) {
			if (m[a[i]] > 0) {
				ans = 0;
				break;
			}
		}
		cout << mx << '\n';
		// if (ans)cout << "yes\n";
		// else cout << "no\n";
	}
	return 0;
}