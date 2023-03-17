#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int cnt = 0;
		for (int i = 1, j = 1; i < 100005 ; i += j, j++) {
			cout << i << ' ';
			cnt++;
		}
		cout << '\n';
		cout << cnt << '\n';
	}
	return 0;
}