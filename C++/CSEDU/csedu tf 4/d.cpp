#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int cs=1;
    w(t){
        ll n,d,c;
        cin >>n>>d>>c;
        ll ara[n];
        ll best=n*d;
        for (ll i=0; i<n; i++){
            cin >>ara[i];
        }
        sort (ara,ara+n);
        for (ll i=0; i<n; i++){
            ll ans =( (i + 1) * ara[i] * c) + ((n - i - 1) * d);
            best = min(best, ans);
        }
        cout <<"Case "<<cs++<<": "<<best<<en;
    }
    return 0;
}