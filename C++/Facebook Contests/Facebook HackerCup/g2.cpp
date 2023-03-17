#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a;
		int odd = 0;
		for (int i = 1; i <= n; i += 2) {
			a.push_back(i);
			odd ^= i;
		}
	}
	return 0;
}