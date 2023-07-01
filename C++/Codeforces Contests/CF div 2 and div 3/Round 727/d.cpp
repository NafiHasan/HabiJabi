#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

struct Compare {
	bool operator()(const pair<ll, ll> &a, const pair<ll, ll> &b) {
		if (a.second != b.second) {
			return a.second > b.second;
		}
		return a.first < b.first;
	}

};
int main() {
	fast_io();
	int n;
	cin >> n;
	vector<pair<ll, ll>>v(n);
	for (int i = 0; i < n; i++)cin >> v[i].first >> v[i].second;
	Compare comp;
	sort(v.begin(), v.end(), comp);
	// for (int i = 0; i < n; i++)cout << v[i].first << " " << v[i].second << en;
	ll cost = 0, done = 0;
	for (int i = n - 1, j = 0; j<n, i >= 0; i--) {
		while (done < v[i].second && j < n && i > -1) {
			if (v[j].first > 0) {
				ll add = min(v[i].second - done, v[j].first);
				v[j].first -= add;
				cost += 2 * add;
				done += add;
			} else j++;
		}
		if (done >= v[i].second) {
			cost += v[i].first;
			done += v[i].first;
			v[i].first = 0;
		}
	}
	cout << cost << en;
	return 0;
}