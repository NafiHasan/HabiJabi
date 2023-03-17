#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n;
	cin >> n;
	vector<pair<ll, ll>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a.begin(), a.end());
	ll cnt = 0;
	map<ll, ll> mp;
	vector<ll> dif;
	for (int i = 1; i < n; i++) {
		ll got = a[i].first - a[i - 1].first;
		dif.push_back(got);
		mp[got]++;
		if (mp[got] == 1)cnt++;
	}
	if (cnt > 3) {
		cout << "-1\n";
		return 0;
	}
	if (n <= 3) {
		cout << "1\n";
		return 0;
	}
	if (cnt == 1) {
		cout << a[0].second << "\n";
		return 0;
	}

	int cn = 0, ans2 = -1;
	for (int i = 1; i < dif.size(); i++) {
		ll sum = dif[i] + dif[i - 1];
		if (i > 1 && sum == dif[0]) {
			if (dif[i] == dif[i - 1] && mp[dif[i]] == 2 && mp[dif[0]] == (dif.size() - 2)) {
				cout << a[i].second << "\n";
				return 0;
				ans2 = a[i].second;
				cn++;
			} else if (dif[i] != dif[i - 1] && mp[dif[i]] == 1 && mp[dif[i - 1]] == 1 && mp[dif[0]] == (dif.size()  - 2)) {
				cout << a[i].second << "\n";
				return 0;
				cn++;
				ans2 = a[i].second;
			}
			// else if(dif[i] == 0 || dif[i - 1] == 0){

			// }
		} else if (i == 1 && sum == dif.back()) {
			if (dif[i] == dif[i - 1] && mp[dif[i]] == 2 && mp[dif.back()] == dif.size() - 2) {
				cout << a[i].second << "\n";
				return 0;
				cn++;
				ans2 = a[i].second;
			} else if (dif[i] != dif[i - 1] && mp[dif[i]] == 1 && mp[dif[i - 1]] == 1 && mp[dif.back()] == dif.size() - 2) {
				cout << a[i].second << "\n";
				return 0;
				cn++;
				ans2 = a[i].second;
			}
		}
	}
	if (cn > 1) {
		cout << "-1\n";
		return 0;
	} else if (cn == 1) {
		cout << ans2 << "\n";
		return 0;
	}

	bool ok = 1;
	for (int i = 2; i < dif.size(); i++) {
		if (dif[i] != dif[i - 1])ok = 0;
	}
	if (ok) {
		if (mp[dif[0]] == 1) {
			cout << a[0].second << '\n';
			return 0;
		}
	}
	ok = 1;
	for (int i = 1; i < dif.size() - 1; i++) {
		if (dif[i] != dif[i - 1]) {
			ok = 0;
			break;
		}
	}
	if (ok) {
		if (mp[dif.back()] == 1) {
			cout << a[dif.size()].second << '\n';
			return 0;
		}
	}

	if (cnt == 2 && mp[0] == 1) {
		for (int i = 0; i < dif.size(); i++) {
			if (dif[i] == 0) {
				cout << a[i].second << "\n";
				return 0;
			}
		}
	}
	cout << "-1\n";
	return 0;
}