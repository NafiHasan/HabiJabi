#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


int main() {
	FastIO;
	int ans = 0;
	for (int i = 1; i <= 29; i += 2)ans ^= i;
	cout << ans << '\n';
	int ans2 = 0;
	// cout << (6 ^ 5) << '\n';
	for (int i = 10000; i <= 49998; i += 2)ans2 ^= i;
	cout << ans2 << '\n';
	return 0;
}