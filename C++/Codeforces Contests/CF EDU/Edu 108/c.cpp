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
		vector<pair<ll, ll>>vp(n);
		for (int i = 0; i < n; i++)cin >> vp[i].first;
		for (int i = 0; i < n; i++)cin >> vp[i].second;
		sort(vp.begin(), vp.end());
		ll mx = 0, ind = 0;
		int cnt = 0;
		vector<ll>v[n];
		for (int i = 0; i < n; i++) {
			if (i && vp[i].first != vp[i - 1].first) ind++;
			v[ind].push_back(vp[i].second);
			mx = max(mx, (ll)v[ind].size());
		}
		vector<ll>csum[n];
		for (int i = 0; i <= ind; i++) {
			ll cur = 0;
			for (int j = v[i].size() - 1; j >= 0; j--) {
				csum[i].push_back(cur + v[i][j]);
				cur += v[i][j];
			}
		}
		vector<ll>ans(n, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < (int)v[i].size(); j++) {
				int mod = (int)v[i].size() % (j + 1);
				int si = (int)csum[i].size();
				ans[j] += csum[i][si - mod - 1];
			}
		}
		for (int i = 0; i < n; i++)cout << ans[i] << " ";
		cout << en;
	}
	return 0;
}