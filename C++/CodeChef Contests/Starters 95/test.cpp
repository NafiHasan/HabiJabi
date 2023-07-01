// C++ implementation to find the
// value of P.Q -1 mod 998244353

#include <bits/stdc++.h>
using namespace std;

// Function to find the value of
// P * Q^-1 mod 998244353
long long calculate(long long p,
                    long long q) {
	long long mod = 1e9 + 7, expo;
	expo = mod - 2;

	// Loop to find the value
	// until the expo is not zero
	while (expo) {

		// Multiply p with q
		// if expo is odd
		if (expo & 1LL) {
			p = (p * q) % mod;
		}
		q = (q * q) % mod;

		// Reduce the value of
		// expo by 2
		expo >>= 1;
	}
	return p;
}

// Driver code
int main() {
	int p = 41, q = 12;

	// Function Call
	cout << calculate(p, q) % (long long)(1e9 + 7) << '\n';
	return 0;
}
