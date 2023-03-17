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
    map<pair<int,int>,int>m;
    vector<pair<int,int>>v(n);
    int ans=1;
    for (int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
        m[{v[i].first, v[i].second}]++;
        ans = max(ans, m[{v[i].first, v[i].second}]);
    }   
    cout << ans << en;
    return 0;
}