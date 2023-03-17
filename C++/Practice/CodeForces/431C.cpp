#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

const ll p=1e9+7;

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n, k, d;
    cin >> n>> k>> d;
    ll way[n+1][2];
    memset(way, 0, sizeof(way));
    way[0][0]=1;
    way[0][1]=0;
    for (ll i=1; i<=n; i++){
        for(ll j=1; j<=k; j++){
            if(i>=j){
                if (j<d) way[i][0] += way[i-j][0];
                else if (j>=d) way[i][1] += way[i-j][0];
                way[i][1]+=way[i-j][1];
                way[i][0]%=p;
                way[i][1]%=p;
            }
        }
    }
    cout << way[n][1]<<en;
    return 0;
}