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
		vector<int> a(n);
		stack<int> st;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			// if(i && i < n-1  && a[i] > a[i-1] && a[i] > a[i+1])ch.push_back(i);
		}
		for (int i =  n - 2 ; i > 0; i--) {
			if (a[i] > a[i - 1] && a[i] > a[i + 1])st.push(i);
		}
		int ans = 0;
		while (!st.empty()) {
			int t = st.top();
			st.pop();
			if (st.empty()) {
				ans++;
				a[t + 1] = a[t];
				break;
			}
			int t2 = st.top();
			if (t + 2 == t2) {
				ans++;
				a[t + 1] = max(a[t], a[t2]);
				st.pop();
			} else {
				a[t + 1] = a[t];
				ans++;
			}
		}
		cout << ans << '\n';
		for (int i = 0; i < n; i++)cout << a[i] << ' ';
		cout << "\n";
	}
	return 0;
}