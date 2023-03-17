#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	int n, k;
	cin >> n >> k;
	k--;
	vector<int> a;
	for (int i = 1; i <= n; i++) a.push_back(i);
	int dead = 0;
	while (a.size() > 1) {
		dead = (dead + k) % a.size();
		a.erase(a.begin() + dead);
	}
	cout << a[0] << '\n';
}