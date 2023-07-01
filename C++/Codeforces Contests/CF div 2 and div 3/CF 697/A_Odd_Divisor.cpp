#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        ll n;
        cin >>n;
        ll a=log2(n);
        if (pow(2,a)==n)cout <<"NO\n";
        else cout <<"YES\n";
    }   
    return 0;
}