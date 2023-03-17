#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<int> cnt(400005, 0);

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first)return 1;
	else if (a.first > b.first)return 0;
	else {
		if (cnt[b.second] > cnt[a.second])return 0;
		else return 1;
	}
}

int main() {
	FastIO;
	int n;
	cin >> n;
	vector<pair<int, int> > a(n), all;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		if (a[i].first > a[i].second)swap(a[i].first, a[i].second);
		cnt[a[i].first]++;
		if (a[i].first != a[i].second)cnt[a[i].second]++;
	}
	sort(a.begin(), a.end(), comp);
	vector<bool> taken(n, 0);
	for (int i = 0; i < 400005; i++) {
		if (cnt[i] > 0) {
			all.push_back({cnt[i], i});
		}
	}
	sort(all.begin(), all.end());
	int ans = 0;
	for (int i = 0; i < all.size(); i++) {
		if (taken[all[i].first])continue;
		ans++;
		taken[all[i].first] = 1;
		int lo = 0, hi = n - 1, mid;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (a[mid].first)
			}
	}
	return 0;
}