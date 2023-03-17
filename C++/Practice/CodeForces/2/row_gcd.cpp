#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,m;
    cin >>n>>m;
    ll ara[n], ara2[m];
    for(int i=0; i<n; i++)cin >>ara[i];   
    for(int i=0; i<m; i++)cin >>ara2[i];
    ll g=0;
    for(int i=1; i<n ; i++){
        g=__gcd(g, abs(ara[i]-ara[0]));
    }   
    for(int i =0; i<m; i++){
        cout << __gcd(g,ara[0]+ara2[i])<<" ";
    }
    cout <<en;
    return 0;
}