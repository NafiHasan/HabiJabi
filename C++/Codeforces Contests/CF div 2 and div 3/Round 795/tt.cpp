#include<bits/stdc++.h>
#define ll long long
#define cig cin.ignore()
#define endl '\n'
const int N = 1e9;
using namespace std;
void solve () {
    ll n;
    vector<ll> c;
    cin >> n;
    vector<ll> a(n), b(n);

    ll test = 0;
    ll diff_test;
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] > 0 && a[i] >= b[i]) c.push_back(a[i] - a[i]) ;
    }
    cout << c[0] << endl;
    diff_test = c[0];

    for (ll i = 0; i < n; i++) {
        ll z_diff = 0;
        ll diff = 0;

        if (b[i] > a[i]) {
            test = 1;
            cout << "NO" << endl;
            break;
        }

        else if (b[i] != 0) {
            diff = a[i] - b[i];
            if (diff != diff_test) {
                test = 1;
                cout << "NO" << endl;
                break;
            }
            if (test == 1) break;
        } else if (b[i] == 0) {

            z_diff = a[i] - b[i];
            if (z_diff > diff_test) {
                test = 1;
                cout << "NO" << endl;
                break;
            }
            if (test == 1) break;
        }
    }

    if (test == 0) cout << "YES" << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    cig;
    while (t--) {
        solve ();
    }
    return 0;
}