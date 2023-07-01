#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a;
		map<int, int> mp;
		while (n > 0) {
			for (int i = 9; i >= 1; i--) {
				if (i <= n && mp[i] == 0) {
					n -= i;
					mp[i]++;
					a.push_back(i);
				}
			}
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < a.size(); i++)cout << a[i];
		cout << '\n';
	}
	return 0;
}