#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const long long mod = 1e9 + 7;

int main() {
	fast_io();
	long long n, p;
	cin >> n >> p;
	vector<long long> a(n);
	map<long long, long long> m;
	long long mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		m[a[i]]++;
	}
	vector<bool> d2(n, 1), d4(n, 1);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long tmp = a[i];
		long long cnt = 0;
		queue<long long> q;
		q.push(tmp);
		bool mk = 0, mk4 = 0;
		while (!q.empty()) {
			cnt++;
			tmp = q.front();
			q.pop();
			if (cnt > 1 && m[tmp] > 0) {
				mk = 1;
				d2[i] = 0;
				ans += cnt;
				ans %= mod;
				break;
			}
			if (tmp * 2 + 1 <= mx)q.push(tmp * 2 + 1);
		}
		cnt = 0;
		q.push(a[i]);
		while (!q.empty()) {
			cnt++;
			tmp = q.front();
			q.pop();
			if (cnt > 1 && m[tmp] > 0) {
				if (mk)cnt--;
				mk = 1;
				d4[i] = 0;
				ans += cnt;
				ans %= mod;
				break;
			}
			if (tmp * 4 <= mx)q.push(tmp * 4);
		}
	}
	cout << ans << '\n';
	for (int i = 0; i < n; i++) {
		if (a[i] == -1)continue;
		long long ad = log2(a[i]);
		cout << ad << '\n' ;
		ad = p - ad;
		cout << ad << '\n';
		if (d2[i] && ad > 0) {
			ans += ad;
			ans %= mod;
		}
		if (ad % 2LL)ad++;
		ad /= 2LL;
		cout << "after " << ad << '\n';
		if (d4[i] && ad > 0) {
			ans += ad;
			ans %= mod;
		}
		if (!d2[i])ans--;
		if (!d4[i])ans--;
	}
	cout << ans << '\n';
	return 0;
}