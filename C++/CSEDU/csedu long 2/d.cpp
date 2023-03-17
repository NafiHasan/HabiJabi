#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"

ll lcm(ll a,ll b){
    ll ans=(a*b)/(__gcd(a,b));
    return ans;
}

int main ()
{
    ll n,a,b,ap,bp;
    cin >>n>>a>>b>>ap>>bp;
    ll lc=lcm(a,b);
    ll aa=(n/a),bb=(n/b),cc=(n/lc),ans;
    if (ap>bp){
        ans=aa*ap+(bb-cc)*bp;
        cout <<ans<<endl;
    }
    else {
        ans=(aa-cc)*ap+ bb*bp;
        cout <<ans<<endl; 
    }
    return 0;
}