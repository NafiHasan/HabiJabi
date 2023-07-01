#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	w(t) {
		int n;
		cin >> n ;
		vector<int>odd, even;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x % 2)odd.push_back(x);
			else even.push_back(x);
		}
		for (int i = 0; i < odd.size(); i++)cout << odd[i] << " ";
		for (int i = 0; i < even.size(); i++)cout << even[i] << " ";
		cout << en;
	}
	return 0;
}