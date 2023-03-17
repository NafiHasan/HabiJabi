#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case " << cs << ": ";
		long long n;
		cin >> n;
		long long precnt = __builtin_popcountll(n);
		n++;
		long long cnt = __builtin_popcountll(n);
		if (cnt > precnt) {
			bool one = 0;
			n--;
			for (long long i = 0; i < 35; i++) {
				if (((1LL << i) & n) != 0)one = 1;
				else {
					if (one) {
						long long num = 0;
						num ^= (1LL << i);
						for (int j = i; j < 35; j++) {
							if (((1LL << j) & n) != 0)num ^= (1LL << j);
						}
						for (int j = 0; j < 35 && precnt != __builtin_popcountll(num); j++) {
							if (((1LL << j) & num) == 0)num ^= (1LL << j);
						}
						n = num;
						break;
					}
				}
			}
		} else {
			for (long long i = 0; i < 35 && (precnt != __builtin_popcountll(n)); i++) {
				if (((1LL << i) & n) == 0) {
					n ^= (1LL << i);
				}
			}
		}
		cout << n << '\n';
	}
	return 0;
}