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
    w(t){
        ll n,k;
        cin >>n>>k;
        n++;k++;
        ll ans=(n%p)*((n+1)%p)/2;
        ans%=p;
        ans*=(k%p);
        ans%=p;
        cout <<ans<<en;
    }   
    return 0;
}