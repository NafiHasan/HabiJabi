#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<int> g(10005, -1);
int cnt = 0;
int grundy(int n) {
	cnt++;
	if (n < 3)return g[n] = 0;
	if (g[n] != -1)return g[n];
	int ans = 0;
	// set<int> st;
	vector<int> st;
	for (int i = 1; i <= (n - 1) / 2; i++) {
		int g1 , g2;
		if (g[i] != -1)g1 = g[i];
		else g1 = grundy(i);
		if (g[n - i] != -1)g2 = g[n - i];
		else g2 = grundy(n - i);
		st.push_back(g1 ^ g2);
		cnt++;
	}
	int cnt1 = 0;
	sort(st.begin(), st.end());
	for (int i = 0; i < 10005; i++) {
		cnt1++;
		if (st[i] != i) {
			ans = i;
			break;
		}
		// st.erase(*st.begin());
	}
	// cout << "cnt1 = " << cnt1 << '\n';
	return g[n] = ans;
}



int main() {
	fast_io();
	grundy(1004);
	cout << cnt << '\n';
	for (int i = 3; i < 1005; i++) {
		// int ans = 0;
		// set<int> st;
		// for (int j = 1; j <= (i - 1) / 2; j++) {
		// 	st.insert((g[j] ^ g[i - j]));
		// 	cnt++;
		// }
		// for (int j = 0; j < 10005; j++) {
		// 	if (*st.begin() != j) {
		// 		ans = j;
		// 		break;
		// 	}
		// 	st.erase(*st.begin());
		// }
		// g[i] = ans;
		cout << i << ' ' << g[i] << '\n';
	}
	// int tc;
	// cin >> tc;
	// for (int cs = 1; cs <= tc; cs++) {
	// 	cout << "Case " << cs << ": ";
	// 	int n;
	// 	cin >> n;
	// 	int ans = 0;
	// 	for (int i = 0; i < n; i++) {
	// 		int x;
	// 		cin >> x;
	// 		ans ^= grundy(x);
	// 	}
	// 	cout << cnt << '\n';
	// 	if (ans == 0)cout << "Bob\n";
	// 	else cout << "Alice\n";
	// }
	return 0;
}


// 0 - 0
// 1 - 0
// 2 - 0
// 3 - 1
// 4 - 0
// 5 - 2
// 6 - 1
// 7 - 0
// 8 - 2
// 9 - 1
// 10 - 0
// 11 - 2
// 12 - 1
// 13 - 3
// 14 - 2
// 15 - 1

