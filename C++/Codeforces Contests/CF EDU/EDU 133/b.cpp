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
		cout << n << '\n';
		int now = 0, fix = n;
		for (int i = 1; i <= n; i++)cout << i << ' ';
		cout << '\n';
		fix = n - 2, now++;
		for (int i = 1; i < n; i++) {
			vector<int> tmp(n + 1);
			for (int j = n - fix + 1; j <= n; j++) {
				tmp[j] = j;
			}
			for (int j = 1, k = 2; j <= n - fix; j++, k++) {
				tmp[j] = k;
			}
			tmp[i + 1] = 1;
			fix--;
			now++;
			for (int j = 1; j <= n; j++)cout << tmp[j] << ' ';
			cout << '\n';
		}
	}
	return 0;
}