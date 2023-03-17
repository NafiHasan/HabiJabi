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
	vector<int>vac, fill;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x)fill.push_back(i);
		else vac.push_back(i);
	}
	int ans = INT_MAX;
	for (int i = 0; i < vac.size(); i++) {
		for (int j = 0; j < fill.size(); j++) {

		}
	}
	return 0;
}