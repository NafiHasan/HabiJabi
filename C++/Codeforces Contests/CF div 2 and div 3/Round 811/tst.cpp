#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, i, j;
        cin >> n;
        int a[n];


        for (i = 0; i < n; i = i + 1) {
            cin >> a[i];
        }

        int z = 0, zn = -1;

        map<int, int> mp;


        for (i = 0; i < n; i = i + 1) {
            // cout<<a[i]<<endl;

            if (a[i] % 10 == 0) {
                z++;
                if (zn == -1)zn = a[i];
                mp[a[i]]++;
            } else if (a[i] % 10 == 5) {
                z++;
                a[i] = a[i] + 5;
                if (zn == -1)zn = a[i];
                mp[a[i]]++;
            }

            else {
                //  cout<<a[i]<<endl;

                while ( (a[i] % 10) != 8) {
                    // cout<<a[i]<<endl;
                    a[i] = a[i] + (a[i] % 10);
                }
            }
        }

        if (z > 0) {
            if (mp[zn] == n) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }

        else {
            sort(a, a + n);

            int c = 0;
            for (i = 1; i < n; i = i + 1) {
                if ((a[i] - a[i - 1]) % 20 != 0) {
                    c++;
                    break;
                }
            }
            if (c == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }

        }

    }
}
