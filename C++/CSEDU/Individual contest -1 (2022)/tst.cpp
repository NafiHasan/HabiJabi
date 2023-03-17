#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    fast_io();
    if ((n == 1 && a[0] > 1) or (a[n - 1] - a[n - 2] > 1)) {
        cout << "NO" << endl;
    }

    else if ((n == 1 && a[0] <= 1) or (a[n - 1] - a[n - 2] <= 1)) cout << "YES" << endl;


    if (n == 1) {
        if (a[0] <= 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    else if (a[n - 1] - a[n - 2] <= 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}