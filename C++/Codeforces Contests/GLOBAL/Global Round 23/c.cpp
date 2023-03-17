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
		map<int, int> ind;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			ind[a[i]] = i + 1;
		}
		for (int i = n ; i >= 1; i--) {
			cout << ind[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}