#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	long long cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '1')cnt++;
		}
		if (cnt % 2)cnt2++;
		else cnt1++;
	}
	cout << (long long) (cnt1 * cnt2) << '\n';
	return 0;
}