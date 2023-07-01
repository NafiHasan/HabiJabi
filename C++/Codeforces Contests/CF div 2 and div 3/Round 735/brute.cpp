#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n, m;
	cin >> n >> m;
	map<int, int>mp;
	for (int i = 0; i <= m ; i++) {
		cout << i << " " << (n ^ i) << "\n";
		mp[(n ^ i)]++;
	}
	for (int i = 0; i <= m + 10; i++) {
		if (mp[i] == 0) {
			cout << i << "\n";
			break;
		}
	}
	return 0;
}