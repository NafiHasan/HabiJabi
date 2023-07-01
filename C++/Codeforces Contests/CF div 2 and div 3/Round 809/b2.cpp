#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long
#define TC(t)           int t;cin >> t;while(t--)
#define FL(t)           for(int i=0;i<t;i++)
#define Y               cout << "YES\n"
#define N               cout << "NO\n"
#define ff first
#define ss second
#define pb push_back
#define pf push_front

#define Fastio          ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define read            freopen("in.txt","r",stdin)
#define write           freopen("out.txt","w",stdout)

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a;
        b >>= 1;
    }
    return res;
}


int main() {
    Fastio

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n], b[n];
        FL(n) cin >> a[i];
        b[0] = 0;
        b[n - 1] = 0;

        for (int i = 1; i < n - 1; i++) {
            if (a[i] <= a[i - 1] || a[i] <= a[i + 1]) {
                b[i] = max(a[i - 1], a[i + 1]) - a[i] + 1;
            } else b[i] = 0;
        }

        ll ans = INT64_MAX, temp = 0;

        if (n % 2) {
            for (int i = 1; i < n; i += 2) {
                temp += b[i];
            }

            ans = temp;
        } else {


            ll c[n], d[n];
            c[0] = 0;
            d[0] = 0;
            d[1] = 0;
            cout << b[0] << endl; // ekhane value 0 ashe

            for (int i = 1; i < n; i += 2) {
                c[i] = c[i - 1] + b[i];
                c[i + 1] = c[i];
            }

            for (int i = 2; i < n; i += 2) {
                d[i] = d[i - 2] + b[i];
                d[i - 1] = d[i];
            }

            d[n - 1] = d[n - 2];
            for (int i = 2; i < n; i += 2) {
                temp = min(c[i] + d[n - 1] - d[i], d[i + 1] + c[n - 1] - c[i]);
                ans = min(ans, temp);
            }

            cout << b[0] << endl; // ekhane value ashe 3000000001




        }
        //cout << ans << endl;
    }

    return 0;
}