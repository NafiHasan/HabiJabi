#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

map<pair<int, int>, int>vis;
int ans[505][505];
map<int, int>cnt;

void dfs(int num, int i, int j) {
	if (vis[ {i, j}] > 0  && j < 0) {
		cout << "-1\n";
		return;
	}
	ans[i][j] = num;
	vis[ {i, j}]++;
	cnt[num]++;
	if (cnt[num] < num) {
		if (vis[ {i, j - 1}] == 0 && j > 0)dfs(num, i, j - 1);
		else dfs(num, i + 1, j);
	}
	return ;
}



int main() {
	fast_io();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		dfs(x, i, i);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cout << ans[i][j] << " ";
		}
		cout << en;
	}
	return 0;
}