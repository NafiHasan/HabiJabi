#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int k;
		cin >> k;
		vector<int> a;
		for (int i = 1; ; i++) {
			if ((int)a.size() >= k)break;
			if (i % 3 == 0 || i % 10 == 3)continue;
			a.push_back(i);
		}
		cout << a.back() << '\n';
	}
	return 0;
}