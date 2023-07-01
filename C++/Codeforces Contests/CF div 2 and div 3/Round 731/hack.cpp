#include <bits/stdc++.h>

#define F first
#define S second
#define p_b push_back
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector < pair < ll, int > > kond(k);
    vector < ll > temp(n, 1e15);
    for (int i = 0; i < k; i++)cin >> kond[i].S;
    for (int i = 0; i < k; i++)cin >> kond[i].F;
    for (int i = 0; i < k; i++) {
        kond[i].S--;
        temp[ kond[i].S ] = kond[i].F;
    }
    sort(all(kond));
    for (int i = 0; i < k; i++) {
        int l = kond[i].S, r = l;

        ll cur = kond[i].F;

        while (l >= 0 && temp[l] >= cur) {
            temp[l] = cur;
            l--; cur++;
        }

        cur = kond[i].F;

        while (r < n && temp[r] >= cur) {
            temp[r] = cur;
            r++; cur++;
        }
    }
    for (int i = 0; i < n; i++)cout << temp[i] << " ";
    cout << endl;
}

int main() {
    int test;
    cin >> test;
    while (test--) solve();
    return 0;
}