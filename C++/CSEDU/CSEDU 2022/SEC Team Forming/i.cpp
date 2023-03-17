#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		long long a, s;
		cin >> a >> s;
		bool ok = 1;
		long long car = 0;
		for (long long i = 0; i < 62; i++) {
			long long bita = (1LL << i) & (a);
			if (bita != 0)bita = 1;
			long long bits = (1LL << i) & (s);
			if (bits != 0)bits = 1;
			if (bita  == 1) {
				if (car == 1 && bits == 1) {
					car = 1;
				}
				if (car == 0 && bits == 1) {
					ok = 0;
					break;
				}
				if (car == 1 && bits == 0) {
					ok = 0;
					break;
					// car = 1;
				} else {
					car = 1;
				}
			} else {
				if (car == 1 && bits == 0) {
					car = 1; //done
				} else if (car == 1 && bits == 1) {
					car = 0;
				}
			}
			// if(bits == 0){
			// 	bits += car;
			// 	car = 0;
			// }
			// else if(bits == 1){
			// 	if(car == 1){
			// 		bits = 0;
			// 		car =
			// 	}
			// }
		}
		if (car > 0)ok = 0;
		if (ok)cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}