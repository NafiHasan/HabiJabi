#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	vector<int> a(n1), ca(n1 + 1, 0) , b(n2), cb(n2 + 1, 0), c(n3), cc(n3 + 1, 0);
	for (int i = 0; i < n1; i++)cin >> a[i];
	for (int i = 0; i < n2; i++)cin >> b[i];
	for (int i = 0; i < n3; i++)cin >> c[i];
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	reverse(c.begin(), c.end());
	map<int, int> mb, mc;
	for (int i = 1; i <= n1; i++) ca[i] += ca[i - 1] + a[i - 1];
	for (int i = 1; i <= n2; i++) {
		cb[i] += cb[i - 1] + b[i - 1];
		mb[cb[i]] = i;
	}
	for (int i = 1; i <= n3; i++) {
		cc[i] += cc[i - 1] + c[i - 1];
		mc[cc[i]] = i;
	}
	if (ca[n1] == cb[n2] && cb[n2] == cc[n3]) {
		cout << ca[n1] << "\n";
		return 0;
	}
	int ans = 0;
	for (int i = n1; i >= 1; i--) {
		if (mb[ca[i]] != 0 && mc[ca[i]] != 0) {
			// ans = n1 - i + n2 - mb[ca[i]] + n3 - mc[ca[i]];
			ans = ca[i];
			// cout << i << ' ' << mb[ca[i]] << ' ' << mc[ca[i]] << '\n';
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}