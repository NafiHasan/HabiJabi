#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"
ll a,b;
vector<ll>v;
void lucky_gen(ll x){
    if (x>10000000000)return ;
    if (x>=a)v.push_back(x);
    lucky_gen(10*x + 4);
    lucky_gen(10*x + 7);
}

int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    cin >> a >> b;
    lucky_gen(0);
    ll ans=0;
    sort (v.begin(), v.end());
    for (int i=0; i<v.size(); i++){
        ll range=min(v[i],b)-a+1;
        ans+= range*v[i];
        a=v[i]+1;
        if (a>b)break;
    }
    cout << ans << en;
    return 0;
}