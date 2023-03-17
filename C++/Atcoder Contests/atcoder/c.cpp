#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    ll n;
    cin >>n;
    ll lim=sqrt(n+2);
    map<ll,ll>m;
    for (ll i=1; i<=lim; i++){
        if (n%i==0 && i!=(n/i)){
            cout <<i<<endl<<n/i<<endl;
        }
        else if (n%i==0 && m[i]==0){
            cout << i << endl;
            m[i]++;
        }
    }
    return 0;
}