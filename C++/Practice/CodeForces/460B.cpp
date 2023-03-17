#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

bool chk(ll sum, ll n){
    ll ans=0;
    while(n){
        ans+=n%10;
        n/=10;
    }
    if (ans==sum)return 1;
    else return 0;
}

int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    ll a , b, c;
    cin  >> a >> b >>c;
    vector<ll>ans;
    for (int i=1; i<=90; i++){
        ll cal=pow(i,a);
        cal=b*cal+c;
        if (chk(i,cal) && cal<(ll)1e9)ans.push_back(cal);
    }
    cout << ans.size() <<en;
    for (int i=0; i<ans.size(); i++) cout << ans[i]<< " " ;
    if (ans.size())cout << en;
    return 0;
}