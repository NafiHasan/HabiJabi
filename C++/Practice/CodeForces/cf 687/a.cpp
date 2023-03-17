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
    
    w(t){
        ll n,m,r,c;
        cin>> n>>m >>r>>c;
        ll c1=abs(r-1)+abs(c-1),c2=abs(r-1)+abs(c-m), c3= abs(r-n)+abs (c-m), c4=abs(r-n)+abs (c-1);
        cout << max({c1,c2,c4,c3})<< en;
    }   
    return 0;
}