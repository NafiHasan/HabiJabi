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
		vector<int> a;
		if (n % 3 == 1) {
			a.push_back(1);
			n--;
		}
		int pre = 1;
		while (n > 0) {
			if (n == 1) {
				a.push_back(1);
				n = 0;
			} else if (pre == 1) {
				a.push_back(2);
				n -= 2;
				pre = 2;
			} else {
				a.push_back(1);
				n--;
				pre = 1;
			}
		}
		for (int i = 0; i < a.size(); i++)cout << a[i] ;
		cout << "\n";
	}
	return 0;
}