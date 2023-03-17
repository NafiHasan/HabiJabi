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
    vector<ll>v(n);
    for (int i=0; i<n; i++)cin >> v[i];
    vector<ll>q1(n+1,0),q2(n+1,0);
    q1[1] = v[0];
    for (int i=2; i<=n; i++) q1[i]+=q1[i-1]+v[i-1];
    sort (v.begin(), v.end());
    q2[1]=v[0];
    for (int i = 2; i <= n; i++) q2[i] += q2[i - 1] + v[i - 1];
    int m;
    cin >> m;
    while(m--){
        ll t, a, b;
        cin >> t >> a >> b;
        if (t==1LL)
            cout << q1[b]-q1[a-1] << en;
        else cout << q2[b]-q2[a-1] << en;
    }
    return 0;
}