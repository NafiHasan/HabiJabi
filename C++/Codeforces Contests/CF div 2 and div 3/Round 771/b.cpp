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
		vector<int> odd, even;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x % 2)odd.push_back(x);
			else even.push_back(x);
		}
		bool ans = 1;
		for (int i = 1; i < odd.size(); i++) {
			if (odd[i] < odd[i - 1])ans = 0;
		}
		for (int i = 1; i < even.size(); i++) {
			if (even[i] < even[i - 1])ans = 0;
		}
		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}