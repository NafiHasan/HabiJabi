#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<long long>;
using vvi = vector<vi>;
using ii = pair<ll, ll>;
using vii = vector<ii>;

int main() {
    int tc = 1;
    cin >> tc;
    for(int t = 0; t < tc; t++) {
        ll n;
        cin >> n;
        vi b(n+2);
        for(ll i = 0; i < n+2; i++) cin >> b[i];
        sort(b.begin(), b.end());
        ll sum = b[n+1];
        ll sum2 = 0;
        bool flag = false;
        for(ll i = 0; i < n+1; i++) sum2 += b[i];
        for(ll i = 0; i < n+1; i++) {
            if(sum2 - b[i] == sum) {
                flag = true;
                b[n+1] = b[i] = -1;
                break;
            }
        }
        if(flag) {
            for(ll i = 0; i <= n+1; i++) {
                if(b[i] != -1) cout << b[i] << " ";
            }
            cout << endl;
            continue;
        }
        sum = b[n];
        sum2 = 0;
        for(ll i = 0; i < n+2; i++) {
            if(i != n)
                sum2 += b[i];
        }
        for(ll i = 0; i < n+2; i++) {
            if(i != n) {
                if(sum2 - b[i] == sum) {
                    flag = true;
                    b[n] = b[i] = -1;
                    break;
                }
            }
        }
        if(flag) {
            for(ll i = 0; i <= n+1; i++) {
                if(b[i] != -1) cout << b[i] << " ";
            }
            cout << endl;
            continue;
        }
        cout << -1 << endl;
    }
    return 0;
}
