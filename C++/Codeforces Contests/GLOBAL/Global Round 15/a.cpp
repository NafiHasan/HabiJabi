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
		string s, sorted;
		cin >> s;
		sorted = s;
		sort(sorted.begin(), sorted.end());
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] != sorted[i])cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}