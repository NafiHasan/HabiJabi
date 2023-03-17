#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long


bool comp (const pair<int, int> &a, const pair<int, int> &b) {
	if (a.first == b.first)return a.second > b.second;
	else return a.first < b.first;
}

int main() {
	fast_io();
	ll n, c;
	cin >> n >> c;
	vector<pair<ll, ll>> hero(n);
	map<ll, ll> mp;
	for (int i = 0; i < n; i++) {
		ll ci, di, hi;
		cin >> ci >> di >> hi;
		double ef = di * hi / ci;
		hero[i] = {di * hi, ef};
		// mp[di * hi] = ci;
	}
	sort(hero.begin(), hero.end(), comp);
	ll m;
	cin >> m;
	vector<ll> vil(m);
	for (int i = 0; i < m; i++) {
		ll di, hi;
		cin >> di >> hi;
		vil[i] = di * hi;
	}

	// for (int i=0; i<m; i++){
	// 	ll find = vil[i] + 1;
	// 	int lo = 0, hi = n-1, mid;
	// 	ll cost = LLONG_MAX;
	// 	while(lo <= hi){
	// 		mid = (lo + hi)/2;
	// 		if(hero[mid].first >= find)
	// 	}
	// }
	return 0;
}