#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n = 100000;
	vector<int> a;
	map<int, int> m;
	int x = 110;
	for (int i = 1; i <= 100; i++) {
		a.push_back(i);
		m[i]++;
	}
	a.push_back(x);
	m[x]++;
	long long cnt = 0;
	for (int i = x + 1; i <= n; i++) {
		bool f = 1;
		for (int j = 0; j < a.size(); j++) {
			cnt++;
			if ((i / a[j]) != i && m[i / a[j]] == 0) {
				f = 0;
				// cout << i << '\n';
				break;
			}
		}
		if (f) {
			m[i]++;
			a.push_back(i);
		}
	}
	cout << cnt << '\n';
	cout << a.size() << '\n';
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << ' ';
	}
	// cout << "nafi";
	return 0;
}