#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"

const ll p = 998244353;

    int
    main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    ll a,b,c;
    cin >>a>>b>>c ;
    ll sum=1;
    sum*=(((a%p)*((a+1)%p))/2)%p;
    sum%= p;
    sum*=(((b%p)*((b+1)%p)/2)%p);
    sum%=p ;
    sum *= (((c%p) * ((c + 1)%p) / 2) % p);
    sum%=p;
    cout <<sum<<en;
    return 0;
}