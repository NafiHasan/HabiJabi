#include<bits/stdc++.h>
using namespace std ;
int main() {
	int t ;
	cin >> t ;
	while (t--) {
		int n;
		cin >> n ;
		int s[n];
		for (int i = 0 ; i < n ; i++) {
			cin >> s[i];
		}
		string v ;
		cin >> v;

		int x , j ;
		for (int i = 0 ; i < n ; i++) {
			if (v[i] == '0') {
				j = i ;
				x = s[i];
				break;
			}
		}
		for (int i = j + 1  ; i < n ; i++) {
			if (v[i] == '0') {
				if (s[i] > x) {
					continue ;
				} else if (s[i] <= x) {
					x = s[i];
				}
			}
		}
		cout << x << endl;

	}
	return 0 ;
}