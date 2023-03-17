#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// long long gcd(long long a, long long b) {
// 	cnt++;
// 	if (a < b)swap(a, b);
// 	if (b == 0)return a;
// 	if(b * 2 <= a){
// 		if(cnt % 2 == 0)
// 	}
// 	return gcd(b, a % b);
// }


int main() {
	FastIO;
	while (1) {
		long long a, b;
		cin >> a >> b;
		if (a == 0)break;
		if (a < b)swap(a, b);
		int cnt = 0;
		while (b != 0) {
			if (b * 2 <= a || a % b == 0) {
				// cnt++;
				break;
			}
			cnt++;
			long long tmp = a % b;
			a = b; b = tmp;
		}
		// if (a >= b * 2LL) {
		// 	cout << "Stan wins\n";
		// 	continue;
		// }
		if (cnt % 2)cout << "Ollie wins\n";
		else cout << "Stan wins\n";
	}
	return 0;
}