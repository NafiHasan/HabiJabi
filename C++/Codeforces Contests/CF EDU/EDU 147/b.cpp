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
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int i = 0; i < n; i++)cin >> b[i];
		int first = -1, last = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				if (first == -1)first = i;
				else last = i;
			}
		}
		while (first > 0) {
			if (b[first] >= b[first - 1])first--;
			else break;
		}
		while (last < n - 1) {
			if (b[last] <= b[last + 1])last++;
			else break;
		}
		cout << first + 1 << ' ' << last + 1 << '\n';
	}
	return 0;
}