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
        ll n,m;
        cin >>n>>m;
        long double place=ceil((sqrt(8*(long double)m+1)-1)/2);
        ll start=(ll)place*(ll)(place-1)/2+1;
        ll y=m-start;
        ll x=((ll)place)-1;
        cout <<"Case "<<cs++<<": "<<x<<" "<<y<<en;
    }   
    return 0;
}