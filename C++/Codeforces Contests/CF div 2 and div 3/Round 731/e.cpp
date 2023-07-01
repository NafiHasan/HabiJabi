#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		int  ac[k];
		vector<int>emp(n, INT_MAX);
		for (int i = 0; i < k; i++)cin >> ac[i];
		// priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ord;
		queue<pair<int, int>>ord;
		for (int i = 0; i < k; i++) {
			int temp;
			cin >> temp;
			ord.push({temp, ac[i] - 1});
		}
		while (!ord.empty()) {
			pair<int, int>now = ord.front();
			ord.pop();
			if (emp[now.second] > now.first) emp[now.second] = now.first;
			if (now.second < n - 1 && emp[now.second + 1] > now.first + 1) {
				emp[now.second + 1] = now.first + 1;
				ord.push({now.first + 1, now.second + 1});
			}
			if (now.second > 0 && emp[now.second - 1] > now.first + 1) {
				emp[now.second - 1] = now.first + 1;
				ord.push({now.first + 1, now.second - 1});
			}
			// if ((int)ord.size() > 250000) {
			// 	cout << "nafi";
			// 	break;
			// }
		}
		for (int i = 0; i < n; i++)cout << emp[i] << " " ;
		cout << "\n";
	}
	return 0;
}