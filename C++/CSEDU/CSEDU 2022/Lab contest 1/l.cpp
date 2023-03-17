#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	while (1) {
		int n, m;
		cin >> n >> m;
		if (n == -1  && m == -1)break;
		priority_queue<pair<int, pair<int, int>>> pq;
		for (int i = 0; i < n; i++) {
			int u;
			cin >> u;
			pq.push({u, {u, 1}});
		}
		m -= n;
		while (m--) {
			pair<int, pair<int, int>> tp = pq.top();
			// cout << pq.top().first << "\n";
			pq.pop();
			int tmp = tp.second.first / (tp.second.second + 1);
			if (tp.second.first % (tp.second.second + 1) != 0)tmp++;
			pq.push({tmp, {tp.second.first, tp.second.second + 1}});
		}
		cout << pq.top().first << "\n";
	}
	return 0;
}