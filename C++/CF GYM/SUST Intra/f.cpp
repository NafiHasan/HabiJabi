#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
const ll mod = 1000000007;
// for (a^n) % p
long long bigmod (long long a, long long n) {
    a %= mod;
    long long ans = 1;
    while (n) {
        if (n & 1) ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

int main() {
    FastIO;
    int tc;
    cin >> tc;
    vector<ll> fact(100005, 1);
    for (ll i = 2; i < 100005; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    while (tc--) {
        ll a, b, n;
        cin >> a >> b >> n;
        if (n == 0)cout << "0\n";
        else {
            cout << bigmod(n, fact[min(a, b)]) << '\n';
        }
    }
    return 0;
}