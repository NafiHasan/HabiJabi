#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int dr[] = { -3, -2, -2, -1, -1, 1};
int dc[] = { -1, 1, -1, -2, -3, -2};


vector<vector<int>> g(510, vector<int> (510, -1));

int grundy(int x, int y) {
	if (x < 2 && y < 2)return g[x][y] = 0;
	if (g[x][y] != -1)return g[x][y];
	set<int> st;
	for (int i = 0; i < 6; i++) {
		int xx = x + dr[i],  yy = y + dc[i];
		if (xx < 0 || yy < 0 || xx > 505 || yy > 505)continue;
		st.insert(grundy(xx, yy));
	}
	// sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < 1000; i++) {
		if (st.empty() || i != *st.begin()) {
			ans = i;
			break;
		}
		st.erase(*st.begin());
	}
	return g[x][y] = ans;
}



int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case " << cs << ": ";
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 0; i < n ; i++) {
			int x, y;
			cin >> x >> y;
			ans ^= grundy(x, y);
			// cout << g[x][y] << '\n';
		}
		if (ans == 0)cout << "Bob\n";
		else cout << "Alice\n";
	}
	return 0;
}