#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	vector<int>all(100005, 0);
	int j = 1;
	for (int i = 1; i <= 100000; i++) {
		if (i % 3 != 0 && i % 10 != 3)all[j++] = i;
	}
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		cout << all[n] << "\n";
	}
	return 0;
}