#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int n;
    cin >> n;
    int a[n],b[n] , cnt=0;
    map<int,int>m;
    for (int i=0; i<n; i++){
        cin >> a[i] >> b[i];
        m[b[i]]++;
    }
    for (int i=0; i<n; i++){
        if (m[a[i]] == 0)
            cnt++;
        if (a[i]==b[i] && m[a[i]]==1)cnt++;
    }
    cout << cnt << en;
    return 0;
}