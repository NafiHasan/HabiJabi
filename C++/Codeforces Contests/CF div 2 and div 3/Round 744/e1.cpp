#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		deque<int>ans;
		for (int i = 0; i < n ; i++) {
			int a;
			cin >> a;
			if (ans.empty())ans.push_back(a);
			else {
				int fr = ans.front(), ba = ans.back();
				if (fr > a)ans.push_front(a);
				else ans.push_back(a);
			}
		}
		for (int i = 0; i < n; i++)cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}