#include <bits/stdc++.h>
using namespace std;
ll power(ll x,int y, int p)
{
    long long res = 1;

    x %= p;

    while (y > 0)
    {

        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
long long modInverse(long long n,
                              int p)
{
    return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
long long nCrModPFermat(long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

// Driver program
int main()
{
    // p must be a prime greater than n.
    int n , r , p = 1e9+7;
    cin >>n>>r;
    cout << "Value of nCr % p is "
         << nCrModPFermat(n, r, p);
    return 0;
}