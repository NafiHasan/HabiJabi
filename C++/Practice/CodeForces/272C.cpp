#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define dbg(x) cout<<#x<<" = "<<x<<en
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 

int main()
{
    fast_io();
    int n;
    cin >> n;
    long long a[n];
    for (int i=0; i<n; i++)cin >> a[i];
    int m;
    cin >> m;
    vector<pair<long,long>>v(m);
    for (int i=0; i<m; i++)cin >>v[i].first >> v[i].second ;
    long long base=0;
    for (int i=0; i<m; i++){
        long long ans=max(base,max(a[0],a[v[i].first-1]));
        base=ans+v[i].second;
        cout << ans << en;
    }
    return 0;
}