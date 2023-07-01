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
		vector<int> b(n), a;
		for (int i = 0; i < n; i++)cin >> b[i];
		a.push_back(b[0]);
		for (int i = 1; i < n; i++) {
			if (b[i] != b[i - 1])a.push_back(b[i]);
		}
		n = a.size();
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (i < n - 1 && a[i + 1] >= a[i]) {
				for (int j = i + 2; j < n; j++) {
					if (a[j] >= a[j - 1]) {
						cnt++;
						i = j - 1;
					} else break;
				}
			} else if (i < n - 1 && a[i + 1] <= a[i]) {
				for (int j = i + 2; j < n; j++) {
					if (a[j] <= a[j - 1]) {
						cnt++;
						i = j - 1;
					} else break;
				}
			}
		}
		cout << n - cnt << '\n';
	}
	return 0;
}